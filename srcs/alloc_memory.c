/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:22:06 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/25 18:22:06 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

t_data		*data = NULL;

static int	init_data()
{
	data = mmap(0, sizeof(data), PROT_READ | PROT_WRITE,
							MAP_ANON | MAP_PRIVATE, -1, 0);
	if (!(data->ptr_tiny = mmap(0, SIZE_ALLOC_TINY, PROT_READ | PROT_WRITE,
							MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (ERROR);
	data->size_tiny = SIZE_ALLOC_TINY;
	if (!(data->ptr_small = mmap(0, SIZE_ALLOC_SMALL, PROT_READ | PROT_WRITE,
							MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (ERROR);
	data->size_small = SIZE_ALLOC_SMALL;
	data->ptr_large = NULL;
	return (SUCCESS);
}

size_t		align(size_t size)
{
	return ((((size - 1) >> 3) << 3) + 8);
}

static void	*alloc_large(size_t size)
{
	void	*ptr;

	if (data->ptr_large == NULL)
	{
		if (!(data->ptr_large = mmap(0, sizeof(t_info) + align(size),
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
	if (!(((t_info*)ptr)->next = mmap(0, sizeof(t_info) + align(size),
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	((t_info*)ptr)->next->size = size;
	((t_info*)ptr)->next->free = false;
	((t_info*)ptr)->next += sizeof(t_info);
	return (((t_info*)ptr)->next);
}

void		*alloc_memory(size_t size)
{
	if (data == NULL)
		if (init_data() == ERROR)
			return (NULL);
	if (size <= SIZE_MAX_TINY)
	{
		printf("TINY allocation\n");
	}
	else if (size <= SIZE_MAX_SMALL)
	{
		printf("SMALL allocation\n");
	}
	else if (size > SIZE_MAX_SMALL)
	{
		printf("LARGE allocation\n");
		return (alloc_large(size));
	}
	return (NULL);
}
