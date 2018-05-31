/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:03:02 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/24 14:03:02 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | show_alloc_mem.c                                         |
**   |     show_alloc_mem(0 lines)                              |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>

static void	print_alloc(void *ptr)
{
	while (ptr)
	{
		if (((t_info*)ptr)->free == false)
			ft_printf("\t%p - %p : "BOLD"%d"EOC" octets\n", ptr + sizeof(t_info),
					ptr + sizeof(t_info) + ((t_info*)ptr)->official_size,
					((t_info*)ptr)->official_size);
		ptr = ((t_info*)ptr)->next;
	}
}

void		show_alloc_mem(void)
{
	void	*ptr;

	ft_printf(YELLOW""BOLD"TINY:"EOC""BOLD" %p\n"EOC, data->ptr_tiny);
	ptr = data->ptr_tiny;
	print_alloc(ptr);
	ft_printf(YELLOW""BOLD"SMALL:"EOC""BOLD" %p\n"EOC, data->ptr_small);
	ptr = data->ptr_small;
	print_alloc(ptr);
	ft_printf(YELLOW""BOLD"LARGE:"EOC""BOLD" %p\n"EOC, data->ptr_large);
	ptr = data->ptr_large;
	print_alloc(ptr);
}
