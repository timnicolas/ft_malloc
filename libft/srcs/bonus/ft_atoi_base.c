/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:04:34 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 15:20:35 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_atoi_base.c                                           |
**   |     ft_atoi_base(7 lines)                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <libft.h>

static int	ft_isbase(char s, char *base)
{
	int		i;

	i = -1;
	while (++i < (int)ft_strlen(base))
		if (ft_tolower(s) == base[i])
			return (1);
	return (0);
}

int			ft_atoi_base(char *s, char *base)
{
	int		i;
	int		res;
	char	c;

	if (ft_strlen(base) < 2 || ft_strlen(base) > 16)
		return (0);
	if (ft_strlen(base) == 16 && *s == '0' && ft_tolower(*(s + 1)) == 'x')
		s += 2;
	else if (ft_strlen(base) == 2 && *s == '0' && ft_tolower(*(s + 1)) == 'b')
		s += 2;
	else if (ft_strlen(base) == 8 && *s == '0')
		++s;
	i = 0;
	while (ft_isbase(*(s + i), base))
		++i;
	if (i == 0)
		return (0);
	c = *(s + i);
	res = ft_base_to_int((((*(s + i) *= 0)) ? s : s), base);
	*(s + i) = c;
	return (res);
}
