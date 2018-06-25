/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:22:06 by tnicolas          #+#    #+#             */
/*   Updated: 2018/06/25 16:25:03 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | alloc_memory.c                                           |
**   |     init_data(8 lines)                                   |
**   |     align(1 lines)                                       |
**   |     init_info_alloc(6 lines)                             |
**   |     alloc_memory(18 lines)                               |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>

t_data		*g_data = NULL;

static int	init_data(void)
{
	g_data = mmap(0, sizeof(g_data), PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	g_data->ptr_tiny = NULL;
	g_data->size_tiny = 0;
	g_data->ptr_small = NULL;
	g_data->size_small = 0;
	g_data->ptr_large = NULL;
	return (SUCCESS);
}

size_t		align(size_t size)
{
	return ((((size - 1) >> 3) << 3) + 8);
}

void		init_info_alloc(t_info *info, t_info *prev, size_t size)
{
	info->size = size;
	info->official_size = size;
	info->next = NULL;
	info->prev = prev;
	info->free = false;
	info->first_in_block = false;
}

void		*alloc_memory(size_t size)
{
	enum e_type_alloc	type;
	size_t				official_size;
	void				*ptr;

	if (g_data == NULL)
		if (init_data() == ERROR)
			return (NULL);
	official_size = size;
	size = align(size);
	type = TYPE_LARGE;
	type = (size <= SIZE_MAX_SMALL) ? TYPE_SMALL : type;
	type = (size <= SIZE_MAX_TINY) ? TYPE_TINY : type;
	if (type == TYPE_LARGE)
		ptr = alloc_large(size);
	else
		ptr = alloc_little(size, type);
	((t_info*)ptr)->official_size = official_size;
	return (ptr + sizeof(t_info));
}
