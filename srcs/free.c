/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:34:53 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/31 13:57:47 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | free.c                                                   |
**   |     free(15 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>

void		free_little(void *ptr, enum e_type_alloc type, t_info *info)
{
	if (info->next == NULL)
	{

	}
}

void		free(void *ptr)
{
	enum e_type_alloc	type;
	t_info				*info;

	if (!ptr)
		return ;
	info = ptr - sizeof(t_info);
	printf("size %zu, %zu\n", info->size, ((t_info*)data->ptr_tiny)->size);
	type = TYPE_LARGE;
	type = (info->size <= SIZE_MAX_SMALL) ? TYPE_SMALL : type;
	type = (info->size <= SIZE_MAX_TINY) ? TYPE_TINY : type;
	if (type == TYPE_LARGE)
		printf("free large\n");
	else
	{
		printf("little free\n");
		free_little(ptr, type, info);
	}
}


//		info->free = true;
//		if (info->next == NULL)
//		{
//			info->prev->next = NULL;
//		}
//		if (info->prev == NULL)
//		{
//			if (info->next->first_in_block == true)
//			{
//				if (info->prev == NULL)
//				{
//					if (type == TYPE_TINY && data->ptr_tiny == ptr - sizeof(t_info))
//						data->ptr_tiny = info->next;
//					if (type == TYPE_SMALL && data->ptr_small == ptr - sizeof(t_info))
//						data->ptr_small = info->next;
//				}
//				else
//					info->prev = (info->prev == NULL) ? NULL : info->prev->prev;
//				if (type == TYPE_TINY)
//				{
//					printf("fruit\n");
//					data->size_tiny -= SIZE_ALLOC_TINY;
//					munmap(info, SIZE_ALLOC_TINY);
//				}
//				else
//				{
//					printf("fruit\n");
//					data->size_tiny -= SIZE_ALLOC_SMALL;
//					munmap(info, SIZE_ALLOC_SMALL);
//				}
//			}
//		}
//		else
//		{
//			if (info->prev && info->prev->free == true)
//			{
//				info->prev->size += info->size + sizeof(t_info);
//				info->prev->next = info->next;
//				if (info->next)
//					info->next->prev = info->prev;
//			}
//			if (info->next && info->next->free == true)
//			{
//				info->size += info->next->size + sizeof(t_info);
//				if (info->next->next)
//					info->next->next->prev = info;
//				info->next = info->next->next;
//			}
//		}
