/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:27:20 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:06 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_conv_o.c                                              |
**   |     ft_get_size_o(25 lines)                              |
**   |     ft_conv_o_type(24 lines)                             |
**   |     ft_get_size_new(8 lines)                             |
**   |     ft_place_nb_o(23 lines)                              |
**   |     ft_conv_o(22 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_get_size_o(t_arg *arg, int *size_nb)
{
	int		sz;
	int		right;
	int		nb_bit;

	if (arg->arg.d > 0)
	{
		nb_bit = sizeof(t_ll) * 8;
		right = nb_bit - nb_bit % 3;
		sz = (sizeof(t_ll) * 8) / 3 + (((sizeof(t_ll) * 8) % 3 == 0) ? 0 : 1);
		while ((right -= 3) >= 0 && --sz)
		{
			if (((arg->arg.d >> right) << (nb_bit - 3) >> (nb_bit - 3)) != 0)
				break ;
		}
		return ((*size_nb = sz) ? sz : sz);
	}
	else if (arg->arg.d == 0)
		return ((*size_nb = 1) ? 1 : 1);
	sz = sizeof(int);
	sz = (ft_getheight(arg) == 'H') ? sizeof(char) : sz;
	sz = (ft_getheight(arg) == 'h') ? sizeof(short) : sz;
	sz = (ft_getheight(arg) == 'l') ? sizeof(long) : sz;
	sz = (ft_getheight(arg) == 'L') ? sizeof(t_ll) : sz;
	*size_nb = (sz * 8) / 3 + (((sz * 8) / 3 == 0) ? 0 : 1);
	return (sz);
}

static int	ft_conv_o_type(char **nbx, int *size_nb, t_arg *arg)
{
	static char	bs[] = "01234567";
	int			left;
	int			nbbit;
	int			i;
	int			sz;

	sz = ft_get_size_o(arg, size_nb);
	if (!(*nbx = malloc(sizeof(char) * (*size_nb + 1))))
		return (ERROR);
	(*nbx)[*size_nb] = '\0';
	nbbit = sizeof(long long) * 8;
	left = nbbit - ((*size_nb) * 3);
	i = 0;
	if (arg->arg.d >= 0)
		(*nbx)[i] = bs[(int)(((t_ull)arg->arg.d << left) >> (nbbit - 3))];
	else if (arg->arg.d < 0 && ft_strchr("H", ft_getheight(arg)))
		(*nbx)[i] = bs[(int)(((t_ull)arg->arg.d << (left + 1)) >> (nbbit - 2))];
	else if (arg->arg.d < 0 && ft_strchr("lL", ft_getheight(arg)))
		(*nbx)[i] = bs[(int)(((t_ull)arg->arg.d << (left + 2)) >> (nbbit - 1))];
	else
		(*nbx)[i] = bs[(int)(((t_ull)arg->arg.d << left) >> (nbbit - 1))];
	while ((left += 3) < nbbit && ++i < *size_nb)
		(*nbx)[i] = bs[(((t_ull)(arg->arg.d << left) >> (nbbit - 3)))];
	return (SUCCESS);
}

static int	ft_get_size_new(t_arg *arg, int size_nb, int *size_new)
{
	*size_new = size_nb;
	if (*size_new > arg->preci)
		*size_new += arg->flag.hashtag;
	if (*size_new <= arg->preci)
		*size_new = arg->preci;
	if (*size_new < arg->wi)
		*size_new = arg->wi;
	return (SUCCESS);
}

static void	ft_place_nb_o(t_arg *arg, char *new, char *nbx, int size_new)
{
	int		start_nbx;
	int		size_nb;

	size_nb = ft_strlen(nbx);
	start_nbx = size_new - size_nb;
	if (arg->flag.minus == 1 && arg->preci >= size_nb)
		start_nbx = arg->preci - size_nb;
	else if (arg->flag.minus == 1)
		start_nbx = 0 + arg->flag.hashtag;
	ft_memset(new, ' ', size_new);
	if (arg->preci == -1 && arg->flag.zero == 1 && arg->flag.minus == 0)
		arg->preci = size_new;
	if (arg->preci != -1 && arg->flag.minus == 0)
		ft_memset((new + size_new - arg->preci), '0', arg->preci);
	else if (arg->preci != -1 && arg->flag.minus == 1)
		ft_memset(new, '0', arg->preci);
	if (arg->flag.hashtag == 1 && arg->flag.minus == 1)
		new[0] = '0';
	else if (arg->flag.hashtag == 1 && arg->preci > size_nb)
		new[size_new - arg->preci - 0] = '0';
	else if (arg->flag.hashtag == 1)
		new[start_nbx - 1] = '0';
	ft_memcpy((new + start_nbx), nbx, size_nb);
}

int			ft_conv_o(char **ret, t_arg *arg)
{
	char	*nbx;
	int		size_nb;
	char	*new;
	int		size_new;

	if (arg->preci == 0 && arg->arg.d == 0)
		return (ft_regle_de_merde(ret, arg));
	if (arg->arg.d == 0)
		arg->flag.hashtag = 0;
	if (ft_conv_o_type(&nbx, &size_nb, arg) == ERROR)
		return (ERROR);
	if (ft_get_size_new(arg, size_nb, &size_new) == ERROR)
		return (ERROR);
	if (!(new = ft_strnew(sizeof(char) * size_new)))
		return (ERROR);
	ft_place_nb_o(arg, new, nbx, size_new);
	if (!(*ret = ft_strfreejoin(*ret, new, size_new, arg)))
		return (ERROR);
	arg->cmpt += size_new;
	free(nbx);
	free(new);
	return (SUCCESS);
}
