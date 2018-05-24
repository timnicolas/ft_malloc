/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrondis_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:24:14 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:05 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_arrondis_f.c                                          |
**   |     ft_resize(8 lines)                                   |
**   |     ft_arrondis_f_get_i(7 lines)                         |
**   |     ft_arrondis_f(25 lines)                              |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static char	*ft_resize(char *s)
{
	int		neg;

	neg = (s[0] == '-') ? 1 : 0;
	if (!(s = ft_realloc(s, ft_strlen(s) + 1, ft_strlen(s) + 2)))
		return (NULL);
	ft_memmove(s + 1 + neg, s + neg, ft_strlen(s) + 1);
	s[neg] = '1';
	return (s);
}

static int	ft_arrondis_f_get_i(char *s, int p)
{
	int		i;

	i = -1;
	while (s[++i] != '.')
		;
	i += (p == -1) ? (8) : (p + 2);
	return (i);
}

char		*ft_arrondis_f(char *s, int p)
{
	int i;

	i = ft_arrondis_f_get_i(s, p);
	while ((--i) ? 1 : 1)
		if (s[i] <= '5')
			break ;
		else
		{
			if (s[i] == '9')
				while (1)
				{
					if (s[i] != '9' && s[i]++)
						return (s);
					else if (s[i] == '9' || s[i] == '-')
					{
						s[i] = (s[i] != '-') ? '0' : s[i];
						if (i-- == 0 || s[i] == '-')
							return (ft_resize(s));
						i -= (s[i] == '.') ? 1 : 0;
					}
				}
			else if ((s[i - 1]++) ? 1 : 1)
				break ;
		}
	return (s);
}
