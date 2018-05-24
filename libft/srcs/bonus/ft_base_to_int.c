/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:46:20 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:25 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_base_to_int.c                                         |
**   |     ft_getbase(8 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <libft.h>

static long long	ft_pow(long long x, long long y)
{
	long long	ret;

	if (y == 0)
		return (1);
	ret = x;
	while (--y > 0)
		ret *= x;
	return (ret);
}

static int			ft_getbase(char c, char *base)
{
	int		ret;

	ret = -1;
	while (base[++ret] != c && base[ret] != '\0')
		;
	if (base[ret] == '\0')
		return (-1);
	return (ret);
}

long long			ft_base_to_int(char *n, char *base)
{
	size_t				sizebase;
	size_t				sizen;
	unsigned long long	ret;
	int					i;
	int					neg;

	sizebase = ft_strlen(base);
	neg = (n[0] == '-') ? 1 : 0;
	sizen = ft_strlen(n) - neg;
	ret = 0;
	i = 0;
	while (++i <= (int)sizen)
		ret += ft_pow(sizebase, i - 1) * ft_getbase(n[sizen - i + neg], base);
	return ((n[0] == '-') ? (long long)-ret : (long long)ret);
}
