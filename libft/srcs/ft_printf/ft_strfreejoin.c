/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:39:55 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:07 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_strfreejoin.c                                         |
**   |     ft_strfreejoin(20 lines)                             |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

char		*ft_strfreejoin(char *s1, const char *s2, int size_s2, t_arg *arg)
{
	char	*retour;
	int		i;
	int		lens1;
	int		lens2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = arg->cmpt;
	lens2 = size_s2;
	if (!(retour = (char *)malloc(sizeof(*retour) * (lens1 + size_s2 + 1))))
		return (NULL);
	i = -1;
	while (++i < lens1)
		retour[i] = s1[i];
	i--;
	while (++i < lens1 + size_s2)
		retour[i] = s2[i - lens1];
	retour[i] = '\0';
	free(s1);
	return (retour);
}
