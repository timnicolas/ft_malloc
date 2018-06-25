/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:03:02 by tnicolas          #+#    #+#             */
/*   Updated: 2018/06/25 16:02:39 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | show_alloc_mem.c                                         |
**   |     print_alloc(22 lines)                                |
**   |     show_alloc_mem(20 lines)                             |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>

static int	print_alloc(void *ptr, size_t *total_octet)
{
	int		i;
	size_t	nb_octet;

	nb_octet = 0;
	i = 0;
	while (ptr)
	{
		if (((t_info*)ptr)->free == false)
		{
			i++;
			nb_octet += ((t_info*)ptr)->official_size;
			ft_printf("\t%p - %p : "BOLD"%d"EOC" octets\n",
					ptr + sizeof(t_info),
					ptr + sizeof(t_info) + ((t_info*)ptr)->official_size,
					((t_info*)ptr)->official_size);
		}
		ptr = ((t_info*)ptr)->next;
	}
	ft_printf(YELLOW""BOLD"\ttotal:"EOC""BOLD" %d"EOC" block ("BOLD"%zu"EOC
			" octets)\n"EOC, i, nb_octet);
	*total_octet += nb_octet;
	return (i);
}

void		show_alloc_mem(void)
{
	void	*ptr;
	int		total;
	size_t	total_octet;

	total_octet = 0;
	total = 0;
	if (!g_data)
		ft_printf(YELLOW""BOLD"total:"EOC""BOLD" %d"EOC" block ("BOLD"%zu"EOC
				" octets)\n"EOC, total, total_octet);
	ft_printf(YELLOW""BOLD"TINY:"EOC""BOLD" %p\n"EOC, g_data->ptr_tiny);
	ptr = g_data->ptr_tiny;
	total += print_alloc(ptr, &total_octet);
	ft_printf(YELLOW""BOLD"SMALL:"EOC""BOLD" %p\n"EOC, g_data->ptr_small);
	ptr = g_data->ptr_small;
	total += print_alloc(ptr, &total_octet);
	ft_printf(YELLOW""BOLD"LARGE:"EOC""BOLD" %p\n"EOC, g_data->ptr_large);
	ptr = g_data->ptr_large;
	total += print_alloc(ptr, &total_octet);
	ft_printf(YELLOW""BOLD"total:"EOC""BOLD" %d"EOC" block ("BOLD"%zu"EOC
			" octets)\n"EOC, total, total_octet);
}
