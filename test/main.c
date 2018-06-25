/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:00:31 by tnicolas          #+#    #+#             */
/*   Updated: 2018/06/25 17:27:49 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | main.c                                                   |
**   |     ft_putnbr_hex(26 lines)                              |
**   |         MEUUUU too many lines                            |
**   |     test_1(21 lines)                                     |
**   |     test_all(10 lines)                                   |
**   |     main(58 lines)                                       |
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
#include <unistd.h>

void	ft_putnbr_hex(int octet, int rem) { char const *base = "0123456789abcdef"; if (rem > 1) ft_putnbr_hex(octet >> 4, rem - 1); write(1, base + (octet % 16), 1); } void	sp_putchar(unsigned char const *ptr) { char const c = *ptr; if (' ' <= c && c <= '~') write(1, ptr, 1); else write(1, ".", 1); } void	print_memory(const void *addr, size_t size) { size_t i; size_t a; unsigned char const *ptr = addr; i = 0; while (i < size) { a = 0; while (a < 16 && a + i < size) { ft_putnbr_hex(*(ptr + i + a), 2); if (a % 2) write(1, " ", 1); a++; } while (a < 16) { write(1, "  ", 2); if (a % 2) write(1, " ", 1); a++; } a = 0; while (a < 16 && a + i < size) { sp_putchar(ptr + a + i); a++; } write(1, "\n", 1); i += 16; } }

#define NB_MALLOC 26
#define SIZE_1 51

int		test_malloc_1(int nb_malloc, int size_start)
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
		if (ft_strlen(s1[i]) != (size_t)size_start + i)
		{
			ft_printf("ERROR bad size %s %s %d\n", __func__, __FILE__, __LINE__);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int			test_malloc(void)
{
	ft_printf("TEST MALLOC:\n");
	ft_printf("\tTINY:\t");
	if (test_malloc_1(100, 0) == ERROR)
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	ft_printf("{green}OK{eoc}\n");
	ft_printf("\tSMALL:\t");
	if (test_malloc_1(100, SIZE_MAX_TINY + 1) == ERROR)
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	ft_printf("{green}OK{eoc}\n");
	ft_printf("\tLARGE:\t");
	if (test_malloc_1(100, SIZE_MAX_SMALL + 1) == ERROR)
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	ft_printf("{green}OK{eoc}\n");
	return (SUCCESS);
}

int			basic_realloc()
{
	char	*s;
	ft_printf("\tBASIC:\t");
	if (!(s = malloc(8)))
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	ft_strcpy(s, "1234567");
	if (!(s = realloc(s, 10)))
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	if (ft_strcmp(s, "1234567") != 0)
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	ft_strcpy(s, "123456789");
	if (ft_strcmp(s, "123456789") != 0)
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	if (!(s = realloc(s, 8)))
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	s[7] = '\0';
	if (ft_strcmp(s, "1234567") != 0)
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	ft_printf("{green}OK{eoc}\n");
	return (SUCCESS);
}

int		test_realloc_1(int nb_malloc, int size_start)
{
	char	*s1;
	int		i;
	int		j;

	if (!(s1 = malloc(size_start)))
		return (ERROR);
	i = -1;
	while (++i < nb_malloc)
	{
		if (!(s1 = realloc(s1, size_start + i)))
			return (ERROR);
		j = -1;
		while (++j < size_start + i)
			s1[j] = 'a' + j % 26;
		s1[j] = '\0';
		if (ft_strlen(s1) != (size_t)size_start + i)
		{
			ft_printf("ERROR bad size %s %s %d\n", __func__, __FILE__, __LINE__);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int			test_realloc_hard()
{
	char	*s1;
	size_t	size;

	size = 100;
	if (!(s1 = malloc(size)))
		return (ERROR);
	if (get_alloc_size(s1) != size)
		return (ERROR);
	size = 1000;
	if (!(s1 = realloc(s1, size)))
		return (ERROR);
	if (get_alloc_size(s1) != size)
		return (ERROR);
	size = 10000;
	if (!(s1 = realloc(s1, size)))
		return (ERROR);
	if (get_alloc_size(s1) != size)
		return (ERROR);
	size = 100;
	if (!(s1 = realloc(s1, size)))
		return (ERROR);
	if (get_alloc_size(s1) != size)
		return (ERROR);
	size = 10000;
	if (!(s1 = realloc(s1, size)))
		return (ERROR);
	if (get_alloc_size(s1) != size)
		return (ERROR);
	return (SUCCESS);
}

int			test_realloc()
{
	ft_printf("TEST REALLOC:\n");
	if (basic_realloc() == ERROR)
		return (ERROR);
	ft_printf("\tTINY:\t");
	if (test_realloc_1(100, 0) == ERROR)
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	ft_printf("{green}OK{eoc}\n");
	ft_printf("\tSMALL:\t");
	if (test_realloc_1(100, SIZE_MAX_TINY + 1) == ERROR)
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	ft_printf("{green}OK{eoc}\n");
	ft_printf("\tLARGE:\t");
	if (test_realloc_1(100, SIZE_MAX_SMALL + 1) == ERROR)
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	ft_printf("{green}OK{eoc}\n");
	ft_printf("\tALL:\t");
	if (test_realloc_1(100, SIZE_MAX_TINY - 50) == ERROR ||
			test_realloc_1(100, SIZE_MAX_SMALL - 50) == ERROR)
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	ft_printf("{green}OK{eoc}\n");
	ft_printf("\tHARD:\t");
	if (test_realloc_hard() == ERROR)
	{
		ft_printf("{red}ERROR{eoc}\n");
		return (ERROR);
	}
	ft_printf("{green}OK{eoc}\n");
	return (SUCCESS);
}

int			main(int ac, char **av)
{
	int		err;

	err = SUCCESS;
	(void)ac;
	(void)av;
	if (test_malloc() == ERROR) {ft_printf("ERROR malloc\n"); return (1);}
	if (test_realloc() == ERROR) {ft_printf("ERROR realloc\n"); return (1);}

//	show_alloc_mem();
	printf("free_all\n");
	free_all();
	show_alloc_mem();
	return (0);
}
