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
	char	*test2;

	(void)ac;
	(void)av;
	size = 20;
	ft_putstr("test = malloc of size 20 with * at pos 8\n");
	test = malloc(size);
	test[8] = 42;
	ft_putstr("test2 = malloc of size 20 with * at pos 0\n");
	test2 = malloc(size);
	test2[1] = 42;
	test2[2] = 42;
	ft_putstr("print_alloc_mem test\n");
	print_alloc_mem(test, size);
	ft_putstr("print_alloc_mem test2\n");
	print_alloc_mem(test2, 0);

	ft_putstr("error on print_alloc_mem and free (bad pointer)\n");
	print_alloc_mem((void*)0x123456, 12);
	free((void*)0x123456);
	show_alloc_mem();
	ft_putstr("free all\n");
	free_all();
	show_alloc_mem();
	return (0);
}
