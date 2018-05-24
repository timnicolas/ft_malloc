/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verrprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:44:42 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/24 17:45:15 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_verrprintf.c                                          |
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

int			ft_verrprintf(const char *format, va_list ap)
{
	char	*str;
	int		ret;

	str = NULL;
	if ((ret = ft_vasprintf(&str, format, ap)) == ERROR)
		return (ERROR);
	if (str != NULL)
		write(STDERR_FILENO, str, ret);
	free(str);
	return (ret);
}
