/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanstars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:54:21 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/08 19:18:27 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_cleanstars.c                                          |
**   |     ft_nb_len(8 lines)                                   |
**   |     ft_stars_width(16 lines)                             |
**   |     ft_nettoyage(19 lines)                               |
**   |     ft_stars_precision(18 lines)                         |
**   |     ft_cleanstars(23 lines)                              |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_nb_len(int nb)
{
	int				nb_len;
	unsigned int	n;

	n = (nb < 0) ? -(unsigned int)nb : (unsigned int)nb;
	nb_len = (nb < 0) ? 2 : 1;
	while (n /= 10)
		nb_len++;
	return (nb_len);
}

static char	*ft_stars_width(char *cpy, va_list ap, int *i)
{
	int stars;
	int total;
	int width;
	int len_width;

	stars = 1;
	while (cpy[++(*i)] == '*')
		stars++;
	*i -= stars;
	total = stars - 0;
	while (--stars >= 0)
		width = va_arg(ap, int);
	len_width = ft_nb_len(width);
	if (!(cpy = ft_replace_stars(cpy, ft_2arg(width, len_width), total, i)))
		return (NULL);
	return (cpy);
}

static char	*ft_nettoyage(char *cpy, int i)
{
	int		j;
	char	*new_net;

	if (!(new_net = ft_strnew(ft_strlen(cpy) - 2)))
		return (NULL);
	j = -1;
	while (++j < i + 1)
	{
		new_net[j] = cpy[j];
	}
	i += 2;
	while (cpy[++i])
	{
		new_net[j] = cpy[i];
		++j;
	}
	if (!(cpy = ft_strdup(new_net)) && ft_free(1, new_net))
		return (NULL);
	return (cpy);
}

static char	*ft_stars_precision(char *cpy, va_list ap, int *i)
{
	int		precision;
	int		len_precision;

	precision = va_arg(ap, int);
	len_precision = ft_nb_len(precision);
	if (precision < 0)
	{
		*i -= 2;
		if (!(cpy = ft_nettoyage(cpy, *i)))
			return (NULL);
	}
	else
	{
		if (!(cpy = ft_replace_stars(cpy, ft_2arg(precision, len_precision),
						1, i)))
			return (NULL);
	}
	return (cpy);
}

int			ft_cleanstars(char **str, va_list ap)
{
	int		i;
	char	*cpy;

	i = -1;
	if (!(cpy = ft_strdup(*str)))
		return (ERROR);
	while (cpy[++i])
	{
		if (cpy[i] == '*')
		{
			if (i > 0 && cpy[i - 1] == '.')
			{
				if (!(cpy = ft_stars_precision(cpy, ap, &i)))
					return (ERROR);
			}
			else if (!(cpy = ft_stars_width(cpy, ap, &i)))
				return (ERROR);
		}
	}
	if (ft_free(1, *str) && !(*str = ft_strdup(cpy)))
		return (ERROR);
	free(cpy);
	return (SUCCESS);
}
