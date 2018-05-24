/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:37:53 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:06 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_conv_b.c                                              |
**   |     ft_conv_b(22 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

int			ft_conv_b(char **ret, t_arg *arg)
{
	int			i;
	int			size;
	int			start;
	long long	nb;
	char		*new_ret;

	size = (arg->preci == -1) ? 64 : arg->preci;
	size += (arg->flag.hashtag == 1) ? 2 : 0;
	if (!(new_ret = ft_strnew(size)))
		return (ERROR);
	new_ret[0] = '0';
	new_ret[1] = (arg->conv == 'b') ? 'b' : 'B';
	nb = arg->arg.d;
	start = (arg->flag.hashtag == 1) ? 2 : 0;
	i = size - start;
	while (--i >= 0)
		new_ret[size - i - 1] = ((nb >> i) & 1) + '0';
	if (!(*ret = ft_strfreejoin(*ret, new_ret, size, arg)))
		return (ERROR);
	arg->cmpt += size;
	free(new_ret);
	return (SUCCESS);
}
