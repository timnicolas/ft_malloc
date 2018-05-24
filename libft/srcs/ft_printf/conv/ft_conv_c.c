/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:28:09 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:06 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_conv_c.c                                              |
**   |     ft_add_conv_c(21 lines)                              |
**   |     ft_length_cs(12 lines)                               |
**   |     ft_conv_c(5 lines)                                   |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

int		ft_add_conv_c(char **ret, t_arg *arg)
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
	if ((arg->flag).minus == 1 || arg->wi < 0)
		tmp[0] = arg->arg.c;
	else
		tmp[size - 1] = arg->arg.c;
	if (!(*ret = ft_strfreejoin(*ret, tmp, size, arg)))
		return (ERROR);
	arg->cmpt += size;
	free(tmp);
	return (SUCCESS);
}

int		ft_length_cs(t_arg *arg)
{
	int		i;
	int		count_l;

	i = -1;
	count_l = 0;
	while (arg->str[++i])
		if (ft_strchr("l", arg->str[i]))
			++count_l;
	if (count_l == 0 || ((count_l % 2) == 0))
		return (SUCCESS);
	else
		return (ERROR);
}

int		ft_conv_c(char **ret, t_arg *arg)
{
	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		return (ft_add_conv_bigc(ret, arg));
	else if (arg->conv == 'c')
		return (ft_add_conv_c(ret, arg));
	return (ERROR);
}
