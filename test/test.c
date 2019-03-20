/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:03:57 by tnicolas          #+#    #+#             */
/*   Updated: 2019/03/20 18:19:57 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

int			main(int ac, char **av)
{
	int		size;
	char	*test;

	(void)ac;
	(void)av;
	size = 20;
	ft_printf("malloc of size %d with * at pos 8\n", size);
	test = malloc(size);
	test[8] = 42;
	print_alloc_mem(test, size);
	show_alloc_mem();
	ft_putstr("free all\n");
	free_all();
	show_alloc_mem();
	return (0);
}
