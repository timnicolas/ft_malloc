/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:34:19 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/08 19:18:28 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_dprintf.c                                             |
**   |     ft_dprintf(15 lines)                                 |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	char	*str;
	int		ret;

	(void)fd;
	(void)str;
	str = NULL;
	va_start(ap, format);
	if ((ret = ft_vasprintf(&str, format, ap)) == ERROR)
	{
		va_end(ap);
		return (ERROR);
	}
	va_end(ap);
	if (str != NULL)
		if (write(fd, str, ret) == -1 && ft_free(1, str))
			return (ERROR);
	free(str);
	return (ret);
}
