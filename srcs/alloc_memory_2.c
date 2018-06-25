/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_memory_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:14:00 by tnicolas          #+#    #+#             */
/*   Updated: 2018/06/25 16:24:56 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | alloc_memory_2.c                                         |
**   |     init(22 lines)                                       |
**   |     alloc_new_slot(22 lines)                             |
**   |     alloc_little_2(20 lines)                             |
**   |     alloc_little(20 lines)                               |
**   |     alloc_large(18 lines)                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>

/*
**	init first block for tiny and small allocation
*/

static int	init(enum e_type_alloc type)
{
	if (type == TYPE_TINY)
	{
		if (!(g_data->ptr_tiny = mmap(0, SIZE_ALLOC_TINY,
						PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (ERROR);
		init_info_alloc(g_data->ptr_tiny, NULL,
				SIZE_ALLOC_TINY - sizeof(t_info));
		((t_info*)g_data->ptr_tiny)->free = true;
		((t_info*)g_data->ptr_tiny)->first_in_block = true;
		g_data->size_tiny = SIZE_ALLOC_TINY;
	}
	else if (type == TYPE_SMALL)
	{
		if (!(g_data->ptr_small = mmap(0, SIZE_ALLOC_SMALL,
						PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (ERROR);
		init_info_alloc(g_data->ptr_small, NULL,
				SIZE_ALLOC_SMALL - sizeof(t_info));
		((t_info*)g_data->ptr_small)->free = true;
		((t_info*)g_data->ptr_small)->first_in_block = true;
		g_data->size_small = SIZE_ALLOC_SMALL;
	}
	return (SUCCESS);
}

/*
**	alloc new memory zone for tiny and small malloc
*/

static int	alloc_new_slot(void *ptr, enum e_type_alloc type)
{
	void	*new;

	if (type == TYPE_TINY)
	{
		if (!(new = mmap(0, SIZE_ALLOC_TINY, PROT_READ | PROT_WRITE,
						MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (ERROR);
		g_data->size_tiny += SIZE_ALLOC_TINY;
	}
	else
	{
		if (!(new = mmap(0, SIZE_ALLOC_SMALL, PROT_READ | PROT_WRITE,
						MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (ERROR);
		g_data->size_tiny += SIZE_ALLOC_SMALL;
	}
	((t_info*)ptr)->next = new;
	init_info_alloc((t_info*)new, ptr, ((type == TYPE_TINY) ? SIZE_ALLOC_TINY :
				SIZE_MAX_SMALL));
	((t_info*)new)->free = true;
	((t_info*)new)->first_in_block = true;
	return (SUCCESS);
}

static void	*alloc_little_2(size_t size, enum e_type_alloc type, void *ptr)
{
	t_info	*tmp;

	if (((t_info*)ptr)->free == true &&
			((t_info*)ptr)->size > size + (sizeof(t_info) * 2))
	{
		((t_info*)ptr)->free = false;
		tmp = ((t_info*)ptr)->next;
		((t_info*)ptr)->next = ptr + sizeof(t_info) + size;
		init_info_alloc(((t_info*)ptr)->next, ptr,
				((t_info*)ptr)->size - size - sizeof(t_info));
		((t_info*)ptr)->size = size;
		((t_info*)ptr)->next->free = true;
		((t_info*)ptr)->next->next = tmp;
		if (tmp)
			tmp->prev = ((t_info*)ptr)->next;
		return (ptr);
	}
	if (alloc_new_slot(ptr, type) == ERROR)
		return (NULL);
	return (alloc_little(size, type));
}

/*
**	allocation TINY and SMALL
*/

void		*alloc_little(size_t size, enum e_type_alloc type)
{
	void	*ptr;
	size_t	size_used;
	size_t	total_size;

	if ((type == TYPE_TINY && g_data->ptr_tiny == NULL) ||
			(type == TYPE_SMALL && g_data->ptr_small == NULL))
		if (init(type) == ERROR)
			return (NULL);
	ptr = (type == TYPE_TINY) ? g_data->ptr_tiny : g_data->ptr_small;
	total_size = (type == TYPE_TINY) ? g_data->size_tiny : g_data->size_small;
	size_used = 0;
	while (((t_info*)ptr)->next)
	{
		if (((t_info*)ptr)->free == true &&
				((t_info*)ptr)->size > size + (sizeof(t_info) * 2))
			break ;
		size_used += ((t_info*)ptr)->size + sizeof(t_info);
		ptr = ((t_info*)ptr)->next;
	}
	return (alloc_little_2(size, type, ptr));
}

/*
**	allocation LARGE
*/

void		*alloc_large(size_t size)
{
	void	*ptr;

	if (g_data->ptr_large == NULL)
	{
		if (!(g_data->ptr_large = mmap(0, sizeof(t_info) + size,
						PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (NULL);
		init_info_alloc((t_info*)g_data->ptr_large, NULL, size);
		return (g_data->ptr_large);
	}
	ptr = g_data->ptr_large;
	while (((t_info*)ptr)->next)
		ptr = ((t_info*)ptr)->next;
	if (!(((t_info*)ptr)->next = mmap(0, sizeof(t_info) + size,
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	init_info_alloc(((t_info*)ptr)->next, ptr, size);
	return (((t_info*)ptr)->next);
}
