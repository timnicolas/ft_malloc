/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:44:51 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/08 19:18:28 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_conv_d.c                                              |
**   |     ft_nb_len_d(9 lines)                                 |
**   |     ft_no_precision(22 lines)                            |
**   |     ft_width(22 lines)                                   |
**   |     ft_precision(19 lines)                               |
**   |     ft_conv_d(23 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_nb_len_d(t_arg *arg)
{
	t_ull	tmp;
	int		sz_nb;

	tmp = (arg->arg.d < 0) ? -(t_ull)arg->arg.d : (t_ull)arg->arg.d;
	sz_nb = (arg->arg.d < 0 || arg->flag.plus == 1 || arg->flag.space == 1) ? 2
		: 1;
	while (tmp /= 10)
		sz_nb++;
	return (sz_nb);
}

static int	ft_no_precision(char **new_ret, t_arg *arg, int sz)
{
	int		sz_total;

	sz_total = ft_nb_len_d(arg);
	sz = (sz_total > sz) ? sz_total : sz;
	if (!((*new_ret) = malloc(sizeof(**new_ret) * (sz + 1))))
		return (ERROR);
	(*new_ret)[sz] = '\0';
	*new_ret = (arg->flag.zero == 1 && arg->flag.minus == 0) ?
		ft_memset(*new_ret, '0', sz) : ft_memset(*new_ret, ' ', sz);
	sz_total = (arg->flag.minus == 0) ? sz : sz_total;
	ft_fill_str_ud(new_ret, arg->arg.d, &sz_total, arg);
	if (arg->arg.d == 0)
		(*new_ret)[--sz_total] = '0';
	if (arg->flag.space == 1 && arg->flag.zero == 1)
		(*new_ret)[0] = ' ';
	if (arg->flag.zero == 1)
		sz_total = 1;
	if (arg->flag.plus == 1 && arg->arg.d >= 0)
		(*new_ret)[sz_total - 1] = '+';
	if (arg->arg.d < 0)
		(*new_ret)[sz_total - 1] = '-';
	return (SUCCESS);
}

static int	ft_width(char **new_ret, char **new_nb, t_arg *arg)
{
	int		sz;
	int		sz_total;

	sz = arg->wi;
	if ((arg->preci == -1) && (ft_no_precision(new_ret, arg, sz) == ERROR))
		return (ERROR);
	else if (arg->preci != -1)
	{
		sz_total = ft_strlen(*new_nb);
		sz = (sz_total > sz) ? sz_total : sz;
		if (!((*new_ret) = malloc(sizeof(char) * (sz + 1))))
			return (ERROR);
		(*new_ret)[sz] = '\0';
		if (arg->preci < arg->wi && ft_memset(*new_ret, ' ', sz))
			if (arg->flag.minus == 0)
				ft_strncpy((*new_ret) + sz - sz_total, *new_nb, sz_total);
			else
				ft_strncpy(*new_ret, *new_nb, sz_total);
		else if (ft_free(1, *new_ret) && !(*new_ret = ft_strdup(*new_nb)))
			return (ERROR);
	}
	return (SUCCESS);
}

static int	ft_precision(char **new_nb, t_arg *arg)
{
	int		sz_total;
	int		sz_nb;

	sz_nb = ft_nb_len_d(arg);
	sz_total = (arg->arg.d < 0 || arg->flag.plus == 1 || arg->flag.space == 1) ?
		(arg->preci + 1) : arg->preci;
	sz_total = (sz_nb > sz_total) ? sz_nb : sz_total;
	if (!((*new_nb) = malloc(sizeof(char) * (sz_total + 1))))
		return (ERROR);
	ft_memset(*new_nb, '0', sz_total);
	if (arg->arg.d < 0)
		(*new_nb)[0] = '-';
	else if (arg->flag.plus == 1 && arg->arg.d >= 0)
		(*new_nb)[0] = '+';
	else if (arg->flag.space == 1)
		(*new_nb)[0] = ' ';
	(*new_nb)[sz_total] = '\0';
	ft_fill_str_ud(new_nb, arg->arg.d, &sz_total, arg);
	return (SUCCESS);
}

int			ft_conv_d(char **ret, t_arg *arg)
{
	char	*new_nb;
	char	*new_ret;
	int		sz;

	new_nb = NULL;
	if (arg->preci == 0 && arg->arg.d == 0)
		return (ft_regle_de_merde(ret, arg));
	if (arg->preci != -1)
	{
		if (ft_precision(&new_nb, arg) == ERROR)
			return (ERROR);
	}
	if (ft_width(&new_ret, &new_nb, arg) == ERROR &&
			ft_free(2, new_ret, new_nb))
		return (ERROR);
	free(new_nb);
	sz = ft_strlen(new_ret);
	if (!(*ret = ft_strfreejoin(*ret, new_ret, sz, arg)) &&
			ft_free(1, new_ret))
		return (ERROR);
	arg->cmpt += sz;
	free(new_ret);
	return (SUCCESS);
}
