/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinnprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:51:50 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/19 12:34:31 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_joinnprintf.c                                         |
**   |     ft_joinnprintf(24 lines)                             |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

int			ft_joinnprintf(char **str, int n, const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		len_str;
	char	*total;
	char	*add_str;

	len_str = (*str == NULL) ? 0 : n;
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
		ft_memcpy(total, *str, len_str) &&
		ft_memcpy(total + len_str, add_str, ret + 1);
	else
		ft_memcpy(total, add_str, ret + 1);
	ft_free(2, *str, add_str);
	*str = total;
	return (ret + len_str);
}
