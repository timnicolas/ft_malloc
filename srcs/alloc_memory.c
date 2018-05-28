/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:22:06 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/28 14:34:29 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | alloc_memory.c                                           |
**   |     init_data(20 lines)                                  |
**   |     align(1 lines)                                       |
**   |     alloc_large(23 lines)                                |
**   |     alloc_little(26 lines)                               |
**   |         MEUUUU too many lines                            |
**   |     alloc_memory(12 lines)                               |
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
	data->ptr_tiny += sizeof(t_info);
	data->size_tiny = SIZE_ALLOC_TINY;
	if (!(data->ptr_small = mmap(0, SIZE_ALLOC_SMALL, PROT_READ | PROT_WRITE,
					MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (ERROR);
	((t_info*)data->ptr_small)->size = 0;
	((t_info*)data->ptr_small)->next = NULL;
	((t_info*)data->ptr_small)->free = true;
	data->ptr_small += sizeof(t_info);
	data->size_small = SIZE_ALLOC_SMALL;
	data->ptr_large = NULL;
	return (SUCCESS);
}

static size_t	align(size_t size)
{
	return ((((size - 1) >> 3) << 3) + 8);
}

/*
**	allocation LARGE
*/
static void	*alloc_large(size_t size)
{
	void	*ptr;

	if (data->ptr_large == NULL)
	{
		if (!(data->ptr_large = mmap(0, sizeof(t_info),
						PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (NULL);
		((t_info*)data->ptr_large)->size = size;
		((t_info*)data->ptr_large)->free = false;
		data->ptr_large += sizeof(t_info);
		return (data->ptr_large);
	}
	ptr = data->ptr_large - sizeof(t_info);
	while (((t_info*)ptr)->next)
		ptr = ((t_info*)ptr)->next - sizeof(t_info);
	if (!(((t_info*)ptr)->next = mmap(0, sizeof(t_info),
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	((t_info*)ptr)->next->size = size;
	((t_info*)ptr)->next->next = NULL;
	((t_info*)ptr)->next->free = false;
	((t_info*)ptr)->next += sizeof(t_info);
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
	((t_info*)ptr)->next = new + sizeof(t_info);
	((t_info*)new)->size = 0;
	((t_info*)new)->next = NULL;
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
	ptr -= sizeof(t_info);
	total_size = (type == TYPE_TINY) ? data->size_tiny : data->size_small;
	size_used = sizeof(t_info);
	while (((t_info*)ptr)->next)
	{
		size_used += ((t_info*)ptr)->size + sizeof(t_info);
		//		printf("\tsize_used %d, %d\n", size_used, ((t_info*)ptr)->size);
		ptr = ((t_info*)ptr)->next - sizeof(t_info);
	}
	if (total_size >= size_used + size + sizeof(t_info))
	{
		((t_info*)ptr)->next = ptr + sizeof(t_info) + ((t_info*)ptr)->size;
		printf("size: %d, addr: %p, next addr: %p, diff: %d\n", size, ptr, ((t_info*)ptr)->next, (void*)((t_info*)ptr)->next - ptr);
		((t_info*)ptr)->next->size = size;
		((t_info*)ptr)->next->next = NULL;
		((t_info*)ptr)->next->free = false;
		((t_info*)ptr)->next += sizeof(t_info);
		return (((t_info*)ptr)->next);
	}
	if (alloc_new_slot(ptr, type) == ERROR)
		return (NULL);
	return (alloc_little(size, type));
}

void		*alloc_memory(size_t size)
{
	enum e_type_alloc	type;

	size = align(size);
	type = TYPE_LARGE;
	type = (size <= SIZE_MAX_SMALL) ? TYPE_SMALL : type;
	type = (size <= SIZE_MAX_TINY) ? TYPE_TINY : type;
	if (data == NULL)
		if (init_data() == ERROR)
			return (NULL);
	if (type == TYPE_LARGE)
		return (alloc_large(size));
	else
		return (alloc_little(size, type));
}
