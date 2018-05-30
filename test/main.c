/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:00:31 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/24 14:00:31 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | main.c                                                   |
**   |     main(12 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>
//#include <stdlib.h>
//#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_hex(int octet, int rem) { char const *base = "0123456789abcdef"; if (rem > 1) ft_putnbr_hex(octet >> 4, rem - 1); write(1, base + (octet % 16), 1); } void	sp_putchar(unsigned char const *ptr) { char const c = *ptr; if (' ' <= c && c <= '~') write(1, ptr, 1); else write(1, ".", 1); } void	print_memory(const void *addr, size_t size) { size_t i; size_t a; unsigned char const *ptr = addr; i = 0; while (i < size) { a = 0; while (a < 16 && a + i < size) { ft_putnbr_hex(*(ptr + i + a), 2); if (a % 2) write(1, " ", 1); a++; } while (a < 16) { write(1, "  ", 2); if (a % 2) write(1, " ", 1); a++; } a = 0; while (a < 16 && a + i < size) { sp_putchar(ptr + a + i); a++; } write(1, "\n", 1); i += 16; } }

#define NB_MALLOC 26
#define SIZE_1 3

int			main(int ac, char **av)
{
	int		i;
	char	*(s1[NB_MALLOC]);

	(void)ac;
	(void)av;
	i = -1;
	while (++i < NB_MALLOC)
	{
		if (!(s1[i] = (char*)malloc(sizeof(char) * (SIZE_1))))
			return (1);
		s1[i][0] = 'a' + i % 26;
		s1[i][1] = 'a' + i % 26;
		s1[i][2] = 'a' + i % 26;
		s1[i][3] = 'a' + i % 26;
		s1[i][4] = 'a' + i % 26;
		s1[i][5] = 'a' + i % 26;
		s1[i][6] = 'a' + i % 26;
		s1[i][7] = '\0';
//		printf("ptr %d: %p\n", i, s1[i]);
	}
	i = -1;
	while (++i < NB_MALLOC)
	{
		printf("string %d: '%s' len(%zu) -> %p\n", i, s1[i], ft_strlen(s1[i]), s1[i]);
	}
	printf("start: %p\n", s1[0] - sizeof(t_info) - sizeof(t_info));
	print_memory(s1[0] - sizeof(t_info) - sizeof(t_info), 200);
	return (0);
}
