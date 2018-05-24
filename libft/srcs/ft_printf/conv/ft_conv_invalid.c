/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_invalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:51:25 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:06 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_conv_invalid.c                                        |
**   |     ft_conv_invalid(22 lines)                            |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

int		ft_conv_invalid(char **ret, t_arg *arg)
{
	char	*new;
	int		len;
	int		i;

	len = (arg->wi == 0) ? 1 : arg->wi;
	if (!(new = malloc(sizeof(*new) * (len + 1))))
		return (ERROR);
	new[len] = '\0';
	ft_memset(new, ' ', len);
	i = 0;
	if ((arg->flag.minus == 0) && (arg->flag.zero == 1))
		while (i < len - 1)
			new[i++] = '0';
	else
		i = len - 1;
	i = (arg->flag.minus == 1) ? 0 : i;
	new[i] = arg->conv;
	if (!(*ret = ft_strfreejoin(*ret, new, len, arg)))
		return (ERROR);
	arg->cmpt += len;
	free(new);
	return (SUCCESS);
}
