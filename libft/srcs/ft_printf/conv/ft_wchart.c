/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:33:18 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:07 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_wchart.c                                              |
**   |     ft_strlenw(10 lines)                                 |
**   |     ft_put_width(12 lines)                               |
**   |     ft_check_mb_cur(18 lines)                            |
**   |     ft_add_conv_bigc(24 lines)                           |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

int			ft_strlenw(wchar_t wch)
{
	if (wch <= 0x7F && wch >= 0)
		return (1);
	if (wch <= 0x7FF && wch >= 0)
		return (2);
	if (wch <= 0xFFFF && wch >= 0)
		return (3);
	if (wch <= 0x10FFFF && wch >= 0)
		return (4);
	else
		return (ERROR);
}

int			ft_put_width(char **tab, t_arg *arg, int *i, int nbb)
{
	size_t size;

	size = nbb;
	*i = 0;
	if (arg->flag.minus == 0 && arg->wi > nbb)
		*i = arg->wi - nbb;
	if (arg->wi > nbb)
		size = arg->wi;
	if (!(*tab = ft_strnew(size)))
		return (ERROR);
	ft_memset(*tab, ' ', size);
	return (SUCCESS);
}

static int	ft_check_mb_cur(char **ret, unsigned wch, t_arg *arg)
{
	char	*tmp;
	int		i;
	int		taille;

	i = 0;
	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		ft_put_width(&tmp, arg, &i, 1);
	else if (!(tmp = ft_strnew(1)))
		return (ERROR);
	tmp[i] = (char)wch;
	taille = ft_strlen(tmp);
	if (wch == 0)
		taille = 1;
	if (!(*ret = ft_strfreejoin(*ret, tmp, taille, arg)))
		return (ERROR);
	free(tmp);
	arg->cmpt += taille;
	return (SUCCESS);
}

int			ft_add_conv_bigc(char **ret, t_arg *arg)
{
	int		sz;
	wint_t	wch;

	wch = (wint_t)arg->arg.c;
	sz = ft_strlenw(wch);
	if (sz == ERROR)
		return (ERROR);
	else if ((wch <= 56319 && wch >= 55296) ||
			(wch >= 0xDB80 && wch <= 0xDBFF) ||
			(wch >= 0xDC00 && wch <= 0xDFFF))
		return (ERROR);
	else if (MB_CUR_MAX == 1 && wch >= 128 && wch <= 255)
		return (ft_check_mb_cur(ret, wch, arg));
	else if (MB_CUR_MAX == 1 && wch > 255)
		return (ERROR);
	else if (sz == 1)
		return (ft_print_oneb(ret, wch, arg));
	else if (sz == 2)
		return (ft_print_twob(ret, wch, arg));
	else if (sz == 3)
		return (ft_print_treeb(ret, wch, arg));
	else if (sz == 4)
		return (ft_print_fourb(ret, wch, arg));
	return (ERROR);
}
