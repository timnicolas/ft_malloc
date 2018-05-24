/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bigs_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:11:43 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/08 19:18:28 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_conv_bigs_2.c                                         |
**   |     ft_strlen_wchart_s(11 lines)                         |
**   |     ft_init_i(6 lines)                                   |
**   |     ft_strcpy_custom_bigs(25 lines)                      |
**   |     ft_taille_str(25 lines)                              |
**   |     ft_add_conv_bigs(24 lines)                           |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_strlen_wchart_s(wchar_t *wstr)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (wstr[k])
	{
		i += ft_strlenw(wstr[k]);
		k++;
	}
	return (i);
}

static void	ft_init_i(int *i, t_arg *arg, int len)
{
	if ((arg->flag).minus == 0 && arg->preci != -1 && arg->preci <= len)
		*i = (arg->wi < len && arg->preci > arg->wi) ? 0 : arg->wi - arg->preci;
	if ((arg->flag).minus == 0 && arg->preci != -1 && arg->preci > len)
		*i = (arg->wi < len ? 0 : arg->wi - len);
	else if ((arg->flag).minus == 0 && arg->preci == -1 && arg->wi >= len)
		*i = arg->wi - len;
}

static int	ft_strcpy_custom_bigs(char **str, t_arg *arg, wchar_t *x,
		int *nbcar)
{
	int		i;
	int		k;
	char	*tmp;
	int		len;

	i = 0;
	k = 0;
	len = ft_strlen_wchart_s(x);
	ft_init_i(&i, arg, len);
	if (!(tmp = ft_strnew(*nbcar)))
		return (ERROR);
	if ((int)(ft_strlen(*str) - *nbcar) != i && arg->flag.minus != 1)
		i = (int)(ft_strlen(*str) - *nbcar);
	while (*x && arg->preci > 0)
	{
		arg->arg.c = *x;
		if (arg->preci > 0 && arg->preci >= ft_strlenw_bigs(*x))
			if (ft_add_conv_bigc(&tmp, arg) == ERROR && ft_free(1, tmp))
				return (ERROR);
		arg->preci -= ft_strlenw_bigs(*x);
		x++;
	}
	str = ft_strw_cpy(str, i, tmp);
	free(tmp);
	return (SUCCESS);
}

static int	ft_taille_str(t_arg *arg, int len)
{
	if (arg->wi != 0 && arg->preci != -1)
	{
		if (arg->preci > arg->wi)
		{
			if (arg->preci < len)
				return (arg->preci);
			else if (arg->preci > len && arg->wi < len)
				return (len);
			else if (arg->preci > len && arg->wi > len)
				return (arg->wi);
			return (len);
		}
		else if (arg->preci < arg->wi)
			return (arg->wi);
		return (arg->preci);
	}
	else if (arg->preci != -1 && arg->wi == 0)
		return (arg->preci);
	else if (arg->preci == -1 && arg->wi != 0)
	{
		if (arg->wi <= len)
			return (len);
		return (arg->wi > len ? arg->wi : arg->wi - len);
	}
	return (len);
}

int			ft_add_conv_bigs(char **ret, t_arg *arg, wchar_t *x, int cmpt)
{
	int		len;
	int		strl;
	int		nbcar;
	char	*str;

	str = NULL;
	len = ft_strlen_wchart_s(x);
	strl = ft_taille_str(arg, len);
	ft_check_nbcar(arg, &nbcar, x, &strl);
	if (!(str = ft_strnew(strl)))
		return (ERROR);
	arg->flag.zero == 1 ? ft_memset(str, '0', strl) : ft_memset(str, ' ', strl);
	if (ft_strcpy_custom_bigs(&str, arg, x, &nbcar) == ERROR)
	{
		arg->flag.zero = 0;
		return (ft_checknull_bigs(ret, arg, &str, &x));
	}
	arg->cmpt = (arg->cmpt != 0) ? arg->cmpt -= nbcar : arg->cmpt;
	arg->cmpt = (cmpt != 0) ? arg->cmpt += cmpt : arg->cmpt;
	if (!(*ret = ft_strfreejoin(*ret, str, strl, arg)))
		return (ERROR);
	arg->cmpt += strl;
	free(str);
	return (SUCCESS);
}
