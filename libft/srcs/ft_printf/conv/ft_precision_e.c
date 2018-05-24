/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_e.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:20:12 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/08 19:18:28 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_precision_e.c                                         |
**   |     ft_tej_zero(23 lines)                                |
**   |     ft_decalage_exposant(25 lines)                       |
**   |     ft_decalage(17 lines)                                |
**   |     calcul_exposant(22 lines)                            |
**   |     ft_precision_e(12 lines)                             |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static char	*ft_tej_zero(char *str)
{
	int		i;
	int		minus;
	int		point;
	int		zero;
	int		new_len;

	i = (str[0] == '-') ? 0 : -1;
	zero = (str[0] == '-') ? 1 : 0;
	minus = (str[0] == '-') ? 1 : 0;
	point = 0;
	while (str[++i] == '0' || str[i] == '.')
	{
		if (str[i] == '.')
			point = 1;
		++zero;
	}
	new_len = ft_strlen(str) - zero;
	ft_memmove(str, str + zero, new_len);
	if (!(str = ft_realloc(str, new_len + zero + minus, new_len + 1 + minus)))
		return (NULL);
	ft_deplace(&str, minus, point, new_len);
	str[new_len] = '\0';
	return (str);
}

static char	*ft_decalage_exposant(char *s, int exposant, t_arg *arg)
{
	char	*cpy;
	int		i;
	int		j;
	int		new_l;

	if (arg->arg.f != 0 && (!(s = ft_tej_zero(s))))
		return (NULL);
	new_l = (s[1] == '.' || s[2] == '.') ? ft_strlen(s) + 4 : ft_strlen(s) + 5;
	if (!(cpy = malloc(sizeof(*cpy) * (new_l + 1))))
		return (NULL);
	i = -1;
	j = -1;
	while (++i < new_l - 4 && ((++j) ? 1 : 1))
		if (i == ((s[0] == '-') ? 2 : 1))
			cpy[i] = (s[j] != '.' && --j) ? '.' : '.';
		else
			cpy[i] = s[j];
	if (!(cpy = ft_arrondis_f(cpy, arg->preci)))
		return (NULL);
	ft_precision_f(cpy, arg->preci);
	cpy = ft_fill_rest_e(cpy, exposant, arg->preci, arg);
	if (ft_free(1, s) && !(s = ft_strdup(cpy)))
		return (NULL);
	free(cpy);
	return (s);
}

static char	*ft_decalage(char *str, t_arg *arg)
{
	int		i;
	int		decalage;
	char	tmp;

	if (!(str = ft_arrondis_f(str, arg->preci)))
		return (NULL);
	i = (str[0] == '-') ? 0 : -1;
	decalage = (str[0] == '-') ? 2 : 1;
	while (str[++i] != '.')
		decalage++;
	while (--decalage > ((str[0] == '-') ? 2 : 1))
	{
		tmp = str[decalage];
		str[decalage] = str[decalage - 1];
		str[decalage - 1] = tmp;
	}
	return (str);
}

int			calcul_exposant(t_arg *arg)
{
	double	tmp;
	int		exposant;

	exposant = 0;
	tmp = (arg->arg.f < 0) ? -(double)arg->arg.f : (double)arg->arg.f;
	if (tmp >= 1)
	{
		while ((int)(tmp + 0.5) >= 10)
		{
			tmp /= 10;
			exposant++;
		}
	}
	else
	{
		while (tmp <= 1)
		{
			tmp *= 10;
			exposant--;
		}
	}
	return (exposant);
}

int			ft_precision_e(char **new_nb, t_arg *arg)
{
	double	f;
	int		exposant;

	f = (arg->arg.f > 0) ? (arg->arg.f) : (-(arg->arg.f));
	if (!(*new_nb = ft_ftoa(f, (arg->arg.f < 0))))
		return (ERROR);
	exposant = calcul_exposant(arg);
	if (!(*new_nb = ft_decalage(*new_nb, arg)))
		return (ERROR);
	if (!(*new_nb = ft_decalage_exposant(*new_nb, exposant, arg)))
		return (ERROR);
	return (SUCCESS);
}
