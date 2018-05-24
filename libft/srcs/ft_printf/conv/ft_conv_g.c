/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:39:19 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/08 19:18:28 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_conv_g.c                                              |
**   |     ft_improve_gf(19 lines)                              |
**   |     ft_improve_ge(25 lines)                              |
**   |     ft_improve_g(9 lines)                                |
**   |     ft_recalcul_precision(8 lines)                       |
**   |     ft_conv_g(25 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_improve_gf(char **new_ret, int len, t_arg *arg)
{
	int		count;
	char	*cpy;

	count = 0;
	while ((*new_ret)[--len] == '0')
		count++;
	if ((*new_ret)[len] == '.')
		count++;
	len = ft_strlen(*new_ret);
	if (!(*new_ret = ft_realloc(*new_ret, len + 1, len - count + 1)))
		return (ERROR);
	(*new_ret)[len - count] = '\0';
	if (ft_flags_e(&cpy, *new_ret, arg) == ERROR)
		return (ERROR);
	free(*new_ret);
	if (!(*new_ret = ft_strdup(cpy)))
		return (ERROR);
	free(cpy);
	return (SUCCESS);
}

static int	ft_improve_ge(char **new_r, int i, int len, t_arg *arg)
{
	int		count;
	int		i_back;
	int		j;
	char	*cpy;

	i_back = i - 1;
	count = 0;
	while ((*new_r)[--i] == '0')
		count++;
	if ((!(cpy = malloc(sizeof(*cpy) * (len - count + 1)))))
		return (ERROR);
	j = -1;
	while (++j < i + 1 || ((j--) ? 0 : 0))
		cpy[j] = (*new_r)[j];
	while (++j < len - count)
		cpy[j] = (*new_r)[++i_back];
	cpy[j] = '\0';
	if (ft_free(1, *new_r) && !(*new_r = ft_strdup(cpy)) && ft_free(1, cpy))
		return (ERROR);
	if (ft_free(1, cpy) && ft_flags_e(&cpy, *new_r, arg) == ERROR)
		return (ERROR);
	if (ft_free(1, *new_r) && !(*new_r = ft_strdup(cpy)))
		return (ERROR);
	free(cpy);
	return (SUCCESS);
}

static int	ft_improve_g(char **new_ret, t_arg *arg)
{
	int		i;
	int		len;

	len = ft_strlen(*new_ret);
	i = -1;
	while ((*new_ret)[++i])
		if ((*new_ret)[i] == 'e')
			return (ft_improve_ge(new_ret, i, len, arg));
	return (ft_improve_gf(new_ret, len, arg));
}

static void	ft_recalcul_precision(t_arg *arg, int exposant)
{
	int		zero_ap;

	zero_ap = ft_calcul_zero_ap(arg);
	arg->preci = (arg->preci == -1) ? 6 : arg->preci;
	if (exposant >= 0 || exposant < -4)
		arg->preci -= (arg->preci == 0) ? 0 : 1;
	else
		arg->preci = arg->preci + zero_ap;
}

int			ft_conv_g(char **ret, t_arg *arg)
{
	int		exposant;
	char	*new_ret;
	double	f;

	exposant = calcul_exposant(arg);
	f = (arg->arg.f > 0) ? (arg->arg.f) : (-(arg->arg.f));
	ft_recalcul_precision(arg, exposant);
	if ((exposant < -4) || (exposant > arg->preci))
	{
		if (ft_precision_e(&new_ret, arg) == ERROR)
			return (ERROR);
	}
	else
	{
		if ((!(new_ret = ft_ftoa(f, (arg->arg.f < 0))))
			|| (!(new_ret = ft_arrondis_f(new_ret, arg->preci))))
			return (ERROR);
		ft_precision_f(new_ret, arg->preci);
	}
	if (ft_improve_g(&new_ret, arg) == ERROR)
		return (ERROR);
	if (!(*ret = ft_strfreejoin(*ret, new_ret, ft_strlen(new_ret), arg)))
		return (ERROR);
	free((arg->cmpt += ft_strlen(new_ret)) ? new_ret : new_ret);
	return (SUCCESS);
}
