/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:22:06 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/31 14:42:33 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | alloc_memory.c                                           |
**   |     init_data(21 lines)                                  |
**   |     align(1 lines)                                       |
**   |     init_info(5 lines)                                   |
**   |     alloc_large(18 lines)                                |
**   |     alloc_new_slot(23 lines)                             |
**   |     alloc_little(32 lines)                               |
**   |         MEUUUU too many lines                            |
**   |     alloc_memory(13 lines)                               |
**   | MEUUUU too many functions                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>

t_data		*data = NULL;

static int	init_data()
{
	data = mmap(0, sizeof(data), PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	data->ptr_tiny = NULL;
	data->size_tiny = 0;
	data->ptr_small = NULL;
	data->size_small = 0;
	data->ptr_large = NULL;
	return (SUCCESS);
}

static size_t	align(size_t size)
{
	return ((((size - 1) >> 3) << 3) + 8);
}

static void	init_info(t_info *info, t_info *prev, size_t size)
{
	info->size = size;
	info->next = NULL;
	info->prev = prev;
	info->free = false;
	info->first_in_block = false;
}

/*
**	allocation LARGE
*/
static void	*alloc_large(size_t size)
{
	void	*ptr;

	if (data->ptr_large == NULL)
	{
		if (!(data->ptr_large = mmap(0, sizeof(t_info) + size,
						PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (NULL);
		init_info((t_info*)data->ptr_large, NULL, size);
		return (data->ptr_large);
	}
	ptr = data->ptr_large;
	while (((t_info*)ptr)->next)
		ptr = ((t_info*)ptr)->next;
	if (!(((t_info*)ptr)->next = mmap(0, sizeof(t_info) + size,
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	init_info(((t_info*)ptr)->next, ptr, size);
	return (((t_info*)ptr)->next);
}

/*
**	alloc new memory zone for tiny and small malloc
*/
static int	alloc_new_slot(void *ptr, enum e_type_alloc type)
{
	void	*new;

	printf("new block\n");
	if (type == TYPE_TINY)
	{
		if (!(new = mmap(0, SIZE_ALLOC_TINY, PROT_READ | PROT_WRITE,
						MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (ERROR);
		data->size_tiny += SIZE_ALLOC_TINY;
	}
	else
	{
		if (!(new = mmap(0, SIZE_ALLOC_SMALL, PROT_READ | PROT_WRITE,
						MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (ERROR);
		data->size_tiny += SIZE_ALLOC_SMALL;
	}
	((t_info*)ptr)->next = new;
	init_info((t_info*)new, ptr, ((type == TYPE_TINY) ? SIZE_ALLOC_TINY :
			SIZE_MAX_SMALL));
	((t_info*)new)->free = true;
	((t_info*)new)->first_in_block = true;
	return (SUCCESS);
}

/*
 *	init first block for tiny and small allocation
 */
static int	init(enum e_type_alloc type)
{
	if (type == TYPE_TINY)
	{
		if (!(data->ptr_tiny = mmap(0, SIZE_ALLOC_TINY, PROT_READ | PROT_WRITE,
						MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (ERROR);
		init_info(data->ptr_tiny, NULL, SIZE_ALLOC_TINY - sizeof(t_info));
		((t_info*)data->ptr_tiny)->free = true;
		((t_info*)data->ptr_tiny)->first_in_block = true;
		data->size_tiny = SIZE_ALLOC_TINY;
	}
	else if (type == TYPE_SMALL)
	{
		if (!(data->ptr_small = mmap(0, SIZE_ALLOC_SMALL, PROT_READ | PROT_WRITE,
						MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (ERROR);
		init_info(data->ptr_small, NULL, SIZE_ALLOC_SMALL - sizeof(t_info));
		((t_info*)data->ptr_small)->free = true;
		((t_info*)data->ptr_small)->first_in_block = true;
		data->size_small = SIZE_ALLOC_SMALL;
	}
	return (SUCCESS);
}

/*
**	allocation TINY and SMALL
*/
static void	*alloc_little(size_t size, enum e_type_alloc type)
{
	void	*ptr;
	t_info	*tmp;
	size_t	size_used;
	size_t	total_size;

	if ((type == TYPE_TINY && data->ptr_tiny == NULL) ||
			(type == TYPE_SMALL && data->ptr_small == NULL))
		if (init(type) == ERROR)
			return (NULL);
	ptr = (type == TYPE_TINY) ? data->ptr_tiny : data->ptr_small;
	total_size = (type == TYPE_TINY) ? data->size_tiny : data->size_small;
	size_used = 0;
	while (((t_info*)ptr)->next)
	{
		if (((t_info*)ptr)->free == true && ((t_info*)ptr)->size > size + sizeof(t_info))
			break ;
		size_used += ((t_info*)ptr)->size + sizeof(t_info);
		ptr = ((t_info*)ptr)->next;
	}
	if (((t_info*)ptr)->free == true && ((t_info*)ptr)->size > size + sizeof(t_info))
	{
		((t_info*)ptr)->free = false;
		tmp = ((t_info*)ptr)->next;
		((t_info*)ptr)->next = ptr + sizeof(t_info) + size;
		init_info(((t_info*)ptr)->next, ptr, ((t_info*)ptr)->size - size - sizeof(t_info));
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

void		*alloc_memory(size_t size)
{
	enum e_type_alloc	type;

	if (data == NULL)
		if (init_data() == ERROR)
			return (NULL);
	size = align(size);
	type = TYPE_LARGE;
	type = (size <= SIZE_MAX_SMALL) ? TYPE_SMALL : type;
	type = (size <= SIZE_MAX_TINY) ? TYPE_TINY : type;
	if (type == TYPE_LARGE)
		return (alloc_large(size) + sizeof(t_info));
	else
		return (alloc_little(size, type) + sizeof(t_info));
}
