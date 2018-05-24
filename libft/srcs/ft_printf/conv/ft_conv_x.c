/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:27:56 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:07 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_conv_x.c                                              |
**   |     ft_get_size_x(24 lines)                              |
**   |     ft_conv_x_type(19 lines)                             |
**   |     ft_get_size_new(7 lines)                             |
**   |     ft_place_nb_x(25 lines)                              |
**   |     ft_conv_x(23 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_get_size_x(t_arg *arg, int *size_nb)
{
	int		sz;
	int		right;
	int		nb_bit;

	if (arg->arg.d > 0)
	{
		nb_bit = sizeof(long long) * 8;
		right = nb_bit;
		sz = sizeof(long long) * 2 + 1;
		while ((right -= 4) >= 0 && --sz)
			if (((arg->arg.d >> right) << (nb_bit - 4) >> (nb_bit - 4)) != 0)
				break ;
		return ((*size_nb = sz) ? sz : sz);
	}
	else if (arg->arg.d == 0)
		return ((*size_nb = 1) ? 1 : 1);
	sz = sizeof(int);
	sz = (ft_getheight(arg) == 'H') ? sizeof(char) : sz;
	sz = (ft_getheight(arg) == 'h') ? sizeof(short) : sz;
	sz = (ft_getheight(arg) == 'l') ? sizeof(long) : sz;
	sz = (ft_getheight(arg) == 'L') ? sizeof(t_ll) : sz;
	sz = (arg->conv == 'p') ? sizeof(t_ll) : sz;
	*size_nb = sz * ((arg->arg.d < 0 || sz == 1) ? 2 : 1);
	return (sz);
}

static int	ft_conv_x_type(char **nbx, int *size_nb, t_arg *arg)
{
	static char	base[] = "0123456789abcdef";
	int			left;
	int			nb_bit;
	int			i;
	int			sz;

	sz = ft_get_size_x(arg, size_nb);
	if (!(*nbx = malloc(sizeof(char) * (*size_nb + 1))))
		return (ERROR);
	(*nbx)[*size_nb] = '\0';
	nb_bit = sizeof(long long) * 8;
	left = nb_bit - ((*size_nb + 1) * 4);
	i = -1;
	while ((left += 4) < nb_bit && ++i < *size_nb)
	{
		(*nbx)[i] = base[(((t_ull)(arg->arg.d << left) >> (nb_bit - 4)))];
		(*nbx)[i] = (arg->conv == 'X') ? ft_toupper((*nbx)[i]) : (*nbx)[i];
	}
	return (SUCCESS);
}

static int	ft_get_size_new(t_arg *arg, int size_nb, int *size_new)
{
	*size_new = size_nb;
	if (*size_new <= arg->preci)
		*size_new = arg->preci;
	*size_new += arg->flag.hashtag * 2;
	if (*size_new < arg->wi)
		*size_new = arg->wi;
	return (SUCCESS);
}

static void	ft_place_nb_x(t_arg *arg, char *new, char *nbx, int size_new)
{
	int		start_nbx;
	int		size_nb;

	size_nb = ft_strlen(nbx);
	start_nbx = size_new - size_nb;
	if (arg->flag.minus == 1 && arg->preci > size_nb)
		start_nbx = arg->preci - size_nb + arg->flag.hashtag * 2;
	else if (arg->flag.minus == 1)
		start_nbx = 0 + arg->flag.hashtag * 2;
	ft_memset(new, ' ', size_new);
	if (arg->preci == -1 && arg->flag.zero == 1 && arg->flag.minus == 0)
		arg->preci = size_new - arg->flag.hashtag * 2;
	if (arg->preci != -1 && arg->flag.minus == 0)
		ft_memset((new + size_new - arg->preci), '0', arg->preci);
	else if (arg->preci != -1 && arg->flag.minus == 1)
		ft_memset(new, '0', arg->preci + ((arg->arg.d == 0) ? 1 : 0));
	if (arg->flag.hashtag == 1 && arg->flag.minus == 1)
		new[1] = ((new[0] -= new[0] - '0') && arg->conv == 'X') ? 'X' : 'x';
	else if (arg->flag.hashtag == 1 && arg->preci > size_nb)
		new[size_new - arg->preci - 1] = ((new[size_new - arg->preci - 2] -=
					new[0] - '0') && arg->conv == 'X') ? 'X' : 'x';
	else if (arg->flag.hashtag == 1)
		new[start_nbx - 1] = ((new[start_nbx - 2] -= new[0] - '0') &&
				arg->conv == 'X') ? 'X' : 'x';
	ft_memcpy((new + start_nbx), nbx, size_nb);
}

int			ft_conv_x(char **ret, t_arg *arg)
{
	char	*nbx;
	int		size_nb;
	char	*new;
	int		size_new;

	arg->flag.hashtag = (arg->conv == 'p') ? 1 : arg->flag.hashtag;
	if (arg->preci == 0 && arg->arg.d == 0)
		return (ft_regle_de_merde(ret, arg));
	if (arg->arg.d == 0 && arg->conv != 'p')
		arg->flag.hashtag = 0;
	if (ft_conv_x_type(&nbx, &size_nb, arg) == ERROR)
		return (ERROR);
	if (ft_get_size_new(arg, size_nb, &size_new) == ERROR)
		return (ERROR);
	if (!(new = ft_strnew(sizeof(char) * size_new)))
		return (ERROR);
	ft_place_nb_x(arg, new, nbx, size_new);
	if (!(*ret = ft_strfreejoin(*ret, new, size_new, arg)))
		return (ERROR);
	arg->cmpt += size_new;
	free(nbx);
	free(new);
	return (SUCCESS);
}
