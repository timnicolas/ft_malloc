/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_allocated.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:23:20 by tnicolas          #+#    #+#             */
/*   Updated: 2018/06/25 18:23:44 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | is_allocated.c                                           |
**   |     is_allocated(20 lines)                               |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>

int			is_allocated(void *ptr)
{
	t_info	*tmp;
	int		i;

	i = -1;
	while (++i < 3)
	{
		if (i == 0)
			tmp = g_data->ptr_tiny;
		else if (i == 1)
			tmp = g_data->ptr_small;
		else if (i == 2)
			tmp = g_data->ptr_large;
		while (tmp)
		{
			if (((void*)tmp) + sizeof(t_info) == ptr)
				return (SUCCESS);
			tmp = tmp->next;
		}
	}
	return (ERROR);
}
