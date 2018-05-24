/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:18:55 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:12 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_vprintf.c                                             |
**   |     ft_vprintf(10 lines)                                 |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

int			ft_vprintf(const char *format, va_list ap)
{
	char	*str;
	int		ret;

	str = NULL;
	if ((ret = ft_vasprintf(&str, format, ap)) == ERROR)
		return (ERROR);
	if (str != NULL)
		write(STDOUT_FILENO, str, ret);
	free(str);
	return (ret);
}
