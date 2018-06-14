/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:00:31 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/31 17:41:32 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | main.c                                                   |
**   |     ft_putnbr_hex(44 lines)                              |
**   |         MEUUUU too many lines                            |
**   |     main(39 lines)                                       |
**   |         MEUUUU too many lines                            |
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
#define SIZE_1 51

int		test_1(int nb_malloc, int size_start)
{
	char	*(s1[nb_malloc]);
	int		i;
	int		j;

	i = -1;
	while (++i < nb_malloc)
	{
		if (!(s1[i] = malloc(size_start + i)))
			return (ERROR);
		j = -1;
		while (++j < size_start + i)
			s1[i][j] = 'a' + j % 26;
		s1[i][j] = '\0';
		printf("s1[i]: '%s' len(%zu)\n", s1[i], ft_strlen(s1[i]));
		if (ft_strlen(s1[i]) != (size_t)size_start + i)
		{
			printf("ERROR bad size %s %s %d\n", __func__, __FILE__, __LINE__);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int			test_all(void)
{
	printf("TEST TINY:\n");
	if (test_1(100, 0) == ERROR)
		return (ERROR);
	printf("TEST SMALL:\n");
	if (test_1(100, SIZE_MAX_TINY + 1) == ERROR)
		return (ERROR);
	printf("TEST LARGE:\n");
	if (test_1(100, SIZE_MAX_SMALL + 1) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int			main(int ac, char **av)
{

	(void)ac;
	(void)av;
//	if (test_all() == ERROR) return (1);

//	char	*s;
//	s = malloc(8);
//	ft_strcpy(s, "1234567");
//	s = realloc(s, 10);
//	ft_printf("str: %s\n", s);
//	ft_strcpy(s, "123456789");
//	ft_printf("str: %s\n", s);
//	s = realloc(s, 8);
//	s[7] = '\0';
//	ft_printf("str: %s\n", s);

//	char	*s1;
//	char	*s2;
//	char	*s3;
//	s2 = malloc(8);
//	ft_strcpy(s2, "1234567");
//	s3 = malloc(8);
//	ft_strcpy(s3, "abcdefg");
//	printf("%p %s\t%s\n", s2, s2, s3);
//	s2 = realloc(s2, 9);
//	printf("%p %s\t%s\n", s2, s2, s3);
//	s1 = malloc(8);
//	printf("%p\n", s1);

//	char	*s1;
//	s1 = malloc(8);
//	show_alloc_mem();
//	s1 = realloc(s1, 16);

//	char	*s1;
//	char	*s2;
//	s1 = malloc(200);
//	s2 = malloc(32);
//	printf("%p\t%p\n", s1, s2);
//	free(s1);
//	s1 = malloc(8);
//	printf("%p\t%p\n", s1, s2);

//	char	*s1;
//	s1 = malloc(30);
//	ft_strcpy(s1, "abcdefghijklmnopqrstuvwxyz");
//	s1 = realloc(s1, SIZE_MAX_TINY + 100);
//	printf("%s\n", s1);

//	char	*s1;
//	s1 = malloc(100);
//
//	show_alloc_mem();
//	printf("free_all\n");
//	free_all();
//	show_alloc_mem();
	return (0);
}
