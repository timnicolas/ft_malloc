/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:10:13 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:05 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_forest.c                                              |
**   |     ft_int_ll_h(14 lines)                                |
**   |     ft_int_ll(20 lines)                                  |
**   |     ft_uint_ull(18 lines)                                |
**   |     ft_forest2(23 lines)                                 |
**   |     ft_forest(21 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static t_ll		ft_int_ll_h(t_arg *arg, va_list ap)
{
	char			ichar;
	unsigned char	uichar;
	short			ishort;
	unsigned short	uishort;

	if (arg->height[1] == 'h')
	{
		ichar = (char)va_arg(ap, int);
		uichar = (unsigned char)((ichar < 0) ? -ichar : ichar);
		return ((ichar < 0) ? -(long long)uichar : (long long)uichar);
	}
	ishort = (short)va_arg(ap, int);
	uishort = (unsigned short)((ishort < 0) ? -ishort : ishort);
	return ((ishort < 0) ? -(long long)uishort : (long long)uishort);
}

static t_ll		ft_int_ll(t_arg *arg, va_list ap)
{
	long			ilong;
	unsigned long	uilong;
	int				iint;
	unsigned int	uiint;

	if ((arg->height[0] == 'j') || (arg->height[0] == 'z'))
		return (va_arg(ap, long long));
	else if (arg->height[0] == 'h')
		return (ft_int_ll_h(arg, ap));
	if (arg->height[0] == 'l')
	{
		if (arg->height[1] == 'l')
			return (va_arg(ap, long long));
		ilong = va_arg(ap, long);
		uilong = (unsigned long)((ilong < 0) ? -ilong : ilong);
		return ((ilong < 0) ? -(long long)uilong : (long long)uilong);
	}
	iint = va_arg(ap, int);
	uiint = (unsigned int)((iint < 0) ? -iint : iint);
	return ((iint < 0) ? -(long long)uiint : (long long)uiint);
}

static t_ull	ft_uint_ull(t_arg *arg, va_list ap)
{
	unsigned char	uchar;
	unsigned short	ushort;

	if (arg->height[0] == 'j' || arg->height[0] == 'z')
		return (va_arg(ap, t_ull));
	else if (arg->height[0] == 'h')
	{
		if (arg->height[1] == 'h')
		{
			uchar = (unsigned char)va_arg(ap, unsigned int);
			return (uchar);
		}
		ushort = (unsigned short)va_arg(ap, int);
		return (ushort);
	}
	if (arg->height[0] == 'l')
		return ((t_ull)va_arg(ap, unsigned long));
	return ((t_ull)va_arg(ap, unsigned int));
}

static int		ft_forest2(char **ret, t_arg *arg, va_list ap)
{
	if (ft_strchr("n", arg->conv) != NULL)
		return (ft_conv_n(ret, ((arg->arg.n = va_arg(ap, int *)) ? arg : arg)));
	else if (ft_strchr("kK", arg->conv) != NULL)
		return (ft_conv_k(ret, (arg->arg.t = va_arg(ap, time_t)) ? arg : arg));
	else if (ft_strchr("%", arg->conv) != NULL)
		return (ft_conv_modulo(ret, arg));
	else if (ft_strchr("bB", arg->conv) != NULL)
		return (ft_conv_b(ret, (arg->arg.d = ft_int_ll(arg, ap)) ? arg : arg));
	else if (ft_strchr("fF", arg->conv) != NULL)
		return (ft_conv_f(ret, (arg->arg.f = va_arg(ap, double)) ? arg : arg));
	else if (ft_strchr("eE", arg->conv) != NULL)
		return (ft_conv_e(ret, (arg->arg.f = va_arg(ap, double)) ? arg : arg));
	else if (ft_strchr("gG", arg->conv) != NULL)
		return (ft_conv_g(ret, (arg->arg.f = va_arg(ap, double)) ? arg : arg));
	else if (ft_strchr("wW", arg->conv) != NULL)
		return (ft_conv_w(ret, ((arg->arg.f = va_arg(ap, double)) ? arg : arg),
				0, 0));
	else if (ft_strchr("r", arg->conv) != NULL)
		return (ft_conv_r(ret, (arg->arg.p = va_arg(ap, void *)) ? arg : arg,
					ap));
	else if (ft_strchr("zjhl", arg->conv) == NULL)
		return (ft_conv_invalid(ret, arg));
	return (SUCCESS);
}

int				ft_forest(char **ret, t_arg *arg, va_list ap)
{
	if (ft_strchr("di", arg->conv) != NULL)
		return (ft_conv_d(ret, (arg->arg.d = ft_int_ll(arg, ap)) ? arg : arg));
	else if (ft_strchr("D", arg->conv) != NULL)
		return (ft_conv_d(ret, (arg->arg.d = va_arg(ap, t_ll)) ? arg : arg));
	else if (ft_strchr("sS", arg->conv) != NULL)
		return (ft_conv_s(ret, (arg->arg.p = va_arg(ap, void *)) ? arg : arg));
	else if (ft_strchr("p", arg->conv) != NULL)
		return (ft_conv_x(ret, (arg->arg.p = va_arg(ap, void *)) ? arg : arg));
	else if (ft_strchr("oO", arg->conv) != NULL)
		return (ft_conv_o(ret, (arg->arg.d = ft_int_ll(arg, ap)) ? arg : arg));
	else if (ft_strchr("u", arg->conv) != NULL)
		return (ft_conv_u(ret, (arg->arg.u =
						ft_uint_ull(arg, ap)) ? arg : arg));
	else if (ft_strchr("U", arg->conv) != NULL)
		return (ft_conv_u(ret, (arg->arg.u = va_arg(ap, t_ull)) ? arg : arg));
	else if (ft_strchr("xX", arg->conv) != NULL)
		return (ft_conv_x(ret, (arg->arg.d = ft_int_ll(arg, ap)) ? arg : arg));
	else if (ft_strchr("cC", arg->conv) != NULL)
		return (ft_conv_c(ret, (arg->arg.c = va_arg(ap, int)) ? arg : arg));
	else
		return (ft_forest2(ret, arg, ap));
}
