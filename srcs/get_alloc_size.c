/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alloc_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:52:54 by tnicolas          #+#    #+#             */
/*   Updated: 2018/06/25 18:02:21 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | get_alloc_size.c                                         |
**   |     check_error(23 lines)                                |
**   |     get_alloc_size(3 lines)                              |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>

static int	check_error(void *ptr)
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
	ft_printf("{red}{bold}ERROR: {eoc}{yellow}get_alloc_size({eoc}ptr=%p"
			"{yellow}){eoc}\n\tcan't return size: pointer not allocated\n",
			ptr);
	return (ERROR);
}

size_t		get_alloc_size(void *ptr)
{
	if (check_error(ptr) == ERROR)
		return (0);
	return (((t_info*)(ptr - sizeof(t_info)))->official_size);
}
