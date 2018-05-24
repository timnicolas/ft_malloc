/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:59:11 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:29 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_strmapi.c                                             |
**   |     ft_strmapi(15 lines)                                 |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <stdlib.h>
#include <libft.h>

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ret;

	if (s == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		;
	if (!(ret = (char*)malloc(sizeof(*ret) * (i + 1))))
		return (NULL);
	i = -1;
	while (s[++i])
		ret[i] = f(i, s[i]);
	ret[i] = '\0';
	return (ret);
}
