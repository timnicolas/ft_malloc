/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:00:11 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:29 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_strstr.c                                              |
**   |     ft_strstr(20 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <libft.h>

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		while (*haystack != *needle && *haystack && *needle)
			haystack++;
		if (*needle == '\0' || *haystack == '\0')
			return (NULL);
		i = 0;
		while (haystack[i] == needle[i] && needle[i])
			i++;
		if (haystack[i - 1] == needle[i - 1] && needle[i] == '\0')
			return ((char*)haystack);
		if (haystack[i] == '\0')
			return (NULL);
		haystack++;
	}
	return (NULL);
}
