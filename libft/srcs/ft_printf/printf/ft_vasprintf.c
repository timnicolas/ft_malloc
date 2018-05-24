/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:55:58 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:07 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_vasprintf.c                                           |
**   |     ft_vasprintf(10 lines)                               |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

int			ft_vasprintf(char **ret, const char *format, va_list ap)
{
	t_arg arg;

	arg.cmpt = 0;
	if (ret == NULL)
		return (ERROR);
	if (ft_parse(ret, format, ap, &arg) == ERROR)
		return (ERROR);
	if (ft_color(ret, &arg) == ERROR)
		return (ERROR);
	return (arg.cmpt);
}
