/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:34:53 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/31 10:21:47 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | free.c                                                   |
**   |     free(27 lines)                                       |
**   |         MEUUUU too many lines                            |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>

void		free(void *ptr)
{
	enum e_type_alloc	type;
	t_info				*info;

	info = ptr - sizeof(t_info);
	printf("size %zu, %zu\n", info->size, ((t_info*)data->ptr_tiny)->size);
	type = TYPE_LARGE;
	type = (info->size <= SIZE_MAX_SMALL) ? TYPE_SMALL : type;
	type = (info->size <= SIZE_MAX_TINY) ? TYPE_TINY : type;
	info->free = true;
	if (info->next == NULL)
	{
		info->prev->next = NULL;
	}
	else if (info->prev == NULL)
	{
		if (info->next == NULL)
			;//free
	}
	if (info->prev && info->prev->free == true)
	{
		info->prev->size += info->size + sizeof(t_info);
		info->prev->next = info->next;
		if (info->next)
			info->next->prev = info->prev;
	}
	if (info->next && info->next->free == true)
	{
		info->size += info->next->size + sizeof(t_info);
		if (info->next->next)
			info->next->next->prev = info;
		info->next = info->next->next;
	}
}
