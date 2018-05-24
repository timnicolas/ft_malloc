/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:06:56 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/08 19:18:28 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_printf.c                                              |
**   |     ft_printf(13 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	int		ret;

	str = NULL;
	va_start(ap, format);
	if ((ret = ft_vasprintf(&str, format, ap)) == ERROR)
	{
		va_end(ap);
		return (ERROR);
	}
	va_end(ap);
	if (str != NULL)
		if (write(STDOUT_FILENO, str, ret) == -1 && ft_free(1, str))
			return (ERROR);
	free(str);
	return (ret);
}
