/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alloc_mem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:20:57 by tnicolas          #+#    #+#             */
/*   Updated: 2018/06/25 19:03:35 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | print_alloc_mem.c                                        |
**   |     print_oct(6 lines)                                   |
**   |     print_char(6 lines)                                  |
**   |     print_memory(22 lines)                               |
**   |     print_alloc_mem(20 lines)                            |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>

static void	print_oct(void *ptr, size_t i, size_t size)
{
	if (i >= size)
		ft_printf("%5s", "");
	else if (i + 1 < size)
		ft_printf("%.4hx ", *((uint16_t*)(ptr + i)));
	else
		ft_printf("%.2hhx%3s", *((uint8_t*)(ptr + i)), "");
}

static void	print_char(void *ptr, size_t i, size_t size)
{
	if (i >= size)
		return ;
	else if (((char*)ptr)[i] >= ' ' && ((char*)ptr)[i] <= '~')
		write(STDOUT_FILENO, ptr + i, 1);
	else
		write(STDOUT_FILENO, ".", 1);
}

static void	print_memory(void *ptr, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < size)
	{
		ft_printf("%p: ", ptr + i);
		j = 0;
		while (j < 16)
		{
			print_oct(ptr, i + j, size);
			j += 2;
		}
		j = 0;
		while (j < 16)
		{
			print_char(ptr, i + j, size);
			++j;
		}
		ft_printf("\n");
		i += 16;
	}
}

/*
**	this function print memory in allocation (for size octet)
**	if size == 0 the function print for the size of the allocation
*/

void		print_alloc_mem(void *ptr, size_t size)
{
	(void)size;
	if (is_allocated(ptr) == ERROR)
	{
		ft_printf("{red}{bold}ERROR: {eoc}{yellow}print_alloc_mem({eoc}ptr=%p"
				"{yellow}){eoc}\n\tcan't print memory: pointer not allocated\n",
				ptr);
		return ;
	}
	if (size > ((t_info*)(ptr - sizeof(t_info)))->official_size)
	{
		ft_printf("{red}{bold}ERROR: {eoc}{yellow}print_alloc_mem({eoc}ptr=%p"
				"{yellow}){eoc}\n\tcan't print memory with size %zu: allocation"
				" size = %zu\n", ptr, size,
				((t_info*)(ptr - sizeof(t_info)))->official_size);
		return ;
	}
	if (size == 0)
		print_memory(ptr, ((t_info*)(ptr - sizeof(t_info)))->official_size);
	else
		print_memory(ptr, size);
}
