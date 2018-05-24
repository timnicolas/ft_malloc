/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:27:05 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/19 11:38:08 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_joinprintf.c                                          |
**   |     ft_joinprintf(23 lines)                              |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

int			ft_joinprintf(char **str, const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		len_str;
	char	*total;
	char	*add_str;

	len_str = (*str == NULL) ? 0 : ft_strlen(*str);
	va_start(ap, format);
	if ((ret = ft_vasprintf(&add_str, format, ap)) == ERROR)
	{
		va_end(ap);
		return (ERROR);
	}
	va_end(ap);
	if (!(total = malloc(sizeof(char) * (ret + len_str + 1))))
		return (ERROR);
	if (len_str > 0)
		ft_strncpy(total, *str, len_str) && ft_strncat(total, add_str, ret + 1);
	else
		ft_strncpy(total, add_str, ret + 1);
	ft_free(2, *str, add_str);
	*str = total;
	return (ret + len_str);
}
