/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanstars_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:02:07 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/08 19:18:27 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_cleanstars_2.c                                        |
**   |     ft_replace_stars_2(11 lines)                         |
**   |     ft_replace_stars(24 lines)                           |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_replace_stars_2(long nb_len, int *j, int *i, char *new)
{
	int		n;
	int		marqueur;

	n = ((ft_get2arg(nb_len, 0) < 0) ? -(unsigned int)ft_get2arg(nb_len, 0) :
			(unsigned int)ft_get2arg(nb_len, 0)) * 10;
	marqueur = *i + ft_get2arg(nb_len, 1);
	while ((n /= 10) > 0)
		new[--(*j)] = n % 10 + '0';
	*j += (ft_get2arg(nb_len, 0) <= 0) ? ft_get2arg(nb_len, 1) - 2 :
		ft_get2arg(nb_len, 1) - 1;
	return (marqueur);
}

char		*ft_replace_stars(char *cpy, long long nb_len, int total, int *i)
{
	int				j;
	int				new_size;
	char			*new;
	int				marqueur;

	new_size = ft_strlen(cpy) + ft_get2arg(nb_len, 1) - total + 1;
	j = -1;
	if (!(new = ft_strnew(new_size + 1)))
		return (NULL);
	while (++j <= *i)
		new[j] = cpy[j];
	new[j] = (ft_get2arg(nb_len, 0) == 0) ? '0' : '-';
	j += ft_get2arg(nb_len, 1);
	marqueur = ft_replace_stars_2(nb_len, &j, i, new);
	*i += total - 1;
	new[++j] = '_';
	while (++j <= new_size)
		new[j] = cpy[++(*i)];
	free(cpy);
	if (!(cpy = ft_strdup(new)) && ft_free(1, new))
		return (NULL);
	free(new);
	*i = marqueur;
	return (cpy);
}
