/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:17:21 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/31 17:41:31 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | free_all.c                                               |
**   |     free_little(13 lines)                                |
**   |     free_large(8 lines)                                  |
**   |     free_all(8 lines)                                    |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>

static void	free_little(void *ptr, enum e_type_alloc type)
{
	void	*to_free;

	if (!ptr)
		return ;
	while (((t_info*)ptr)->next)
		ptr = ((t_info*)ptr)->next;
	while (ptr)
	{
		if (((t_info*)ptr)->first_in_block == true)
			to_free = ptr;
		ptr = ((t_info*)ptr)->prev;
		munmap(to_free, (type == TYPE_TINY) ? SIZE_ALLOC_TINY : SIZE_MAX_SMALL);
	}
}

static void	free_large(void *ptr)
{
	void	*to_free;

	while (ptr)
	{
		to_free = ptr;
		ptr = ((t_info*)ptr)->next;
		munmap(to_free, ((t_info*)to_free)->size + sizeof(t_info));
	}
}

void		free_all(void)
{
	free_little(g_data->ptr_tiny, TYPE_TINY);
	g_data->ptr_tiny = NULL;
	g_data->size_tiny = 0;
	free_little(g_data->ptr_small, TYPE_SMALL);
	g_data->ptr_small = NULL;
	g_data->size_small = 0;
	free_large(g_data->ptr_large);
	g_data->ptr_large = NULL;
}
