/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:22:06 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/30 15:26:47 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | alloc_memory.c                                           |
**   |     init_data(19 lines)                                  |
**   |     align(1 lines)                                       |
**   |     init_info(3 lines)                                   |
**   |     alloc_large(18 lines)                                |
**   |     alloc_new_slot(20 lines)                             |
**   |     alloc_little(25 lines)                               |
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
	if (!(data->ptr_tiny = mmap(0, SIZE_ALLOC_TINY, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (ERROR);
	((t_info*)data->ptr_tiny)->size = 0;
	((t_info*)data->ptr_tiny)->next = NULL;
	((t_info*)data->ptr_tiny)->free = true;
	data->size_tiny = SIZE_ALLOC_TINY;
	if (!(data->ptr_small = mmap(0, SIZE_ALLOC_SMALL, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (ERROR);
	((t_info*)data->ptr_small)->size = 0;
	((t_info*)data->ptr_small)->next = NULL;
	((t_info*)data->ptr_small)->free = true;
	data->size_small = SIZE_ALLOC_SMALL;
	data->ptr_large = NULL;
	printf("{\n\tptr_tiny: %p,\n\tptr_small: %p\n}\n", data->ptr_tiny, data->ptr_small);
	return (SUCCESS);
}

static size_t	align(size_t size)
{
	return ((((size - 1) >> 3) << 3) + 8);
}

static void	init_info(t_info *info, size_t size)
{
	info->size = size;
	info->next = NULL;
	info->free = false;
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
		init_info((t_info*)data->ptr_large, size);
		return (data->ptr_large);
	}
	ptr = data->ptr_large;
	while (((t_info*)ptr)->next)
		ptr = ((t_info*)ptr)->next;
	if (!(((t_info*)ptr)->next = mmap(0, sizeof(t_info) + size,
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	init_info(((t_info*)ptr)->next, size);
	return (((t_info*)ptr)->next);
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
	init_info((t_info*)new, 0);
	((t_info*)new)->free = true;
	return (SUCCESS);
}

/*
**	allocation TINY and SMALL
*/
static void	*alloc_little(size_t size, enum e_type_alloc type)
{
	void	*ptr;
	size_t	size_used;
	size_t	total_size;

	ptr = (type == TYPE_TINY) ? data->ptr_tiny : data->ptr_small;
	total_size = (type == TYPE_TINY) ? data->size_tiny : data->size_small;
	size_used = 0;
	while (((t_info*)ptr)->next)
	{
		size_used += ((t_info*)ptr)->size + sizeof(t_info);
		ptr = ((t_info*)ptr)->next;
	}
	if (total_size >= size_used + size + sizeof(t_info))
	{
		((t_info*)ptr)->next = ptr + sizeof(t_info) + ((t_info*)ptr)->size;
		init_info(((t_info*)ptr)->next, size);
		return (((t_info*)ptr)->next);
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
