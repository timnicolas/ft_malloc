/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_e_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:38:25 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:07 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_precision_e_2.c                                       |
**   |     ft_nb_len_e(9 lines)                                 |
**   |     ft_fill_rest_e(16 lines)                             |
**   |     ft_deplace(10 lines)                                 |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_nb_len_e(int nb)
{
	unsigned int	tmp;
	int				nb_len;

	tmp = (nb < 0) ? -(unsigned int)nb : (unsigned int)nb;
	nb_len = 1;
	while (tmp /= 10)
		nb_len++;
	nb_len = (nb_len < 2) ? 2 : nb_len;
	return (nb_len);
}

char		*ft_fill_rest_e(char *cpy, int exposant, int precision, t_arg *arg)
{
	int		e_len;
	int		i;

	precision = (precision == -1) ? 6 : precision;
	i = (cpy[0] == '-') ? precision + 3 : precision + 2;
	i = (precision == 0) ? i - 1 : i;
	e_len = ft_nb_len_e(exposant);
	cpy[i] = (ft_islower(arg->conv)) ? 'e' : 'E';
	cpy[++i] = (exposant < 0) ? '-' : '+';
	cpy[i + e_len + 1] = '\0';
	while (--e_len >= 0)
	{
		cpy[i + e_len + 1] = ft_abs(exposant) % 10 + '0';
		exposant /= 10;
	}
	return (cpy);
}

void		ft_deplace(char **str, int minus, int point, int new_len)
{
	if (minus == 1)
	{
		ft_memmove(*str + 1, *str, new_len - 1 - point);
		(*str)[0] = '-';
	}
	if (point == 1)
	{
		ft_memmove(*str + 2 + minus, *str + 1 + minus, new_len - 1 - minus);
		(*str)[1 + minus] = '.';
	}
}
