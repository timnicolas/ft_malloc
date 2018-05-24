/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_modulo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:12:33 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:06 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_conv_modulo.c                                         |
**   |     ft_conv_modulo(21 lines)                             |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

int		ft_conv_modulo(char **ret, t_arg *arg)
{
	char	*tmp;
	size_t	size;

	size = 1;
	if (arg->wi > 0)
		size = arg->wi;
	if (!(tmp = ft_strnew(size)))
		return (ERROR);
	if (arg->flag.zero == 1 && arg->flag.minus == 0)
		ft_memset(tmp, '0', size);
	else if (!(ft_memset(tmp, ' ', size)))
		return (ERROR);
	if (arg->flag.minus == 1)
		tmp[0] = '%';
	else
		tmp[size - 1] = '%';
	if (!(*ret = ft_strfreejoin(*ret, tmp, size, arg)))
		return (ERROR);
	arg->cmpt += size;
	free(tmp);
	return (SUCCESS);
}
