/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:47:47 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:27 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_itoa.c                                                |
**   |     ft_itoa(19 lines)                                    |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <stdlib.h>

char		*ft_itoa(int n)
{
	int				size_str;
	char			*str;
	unsigned int	n2;

	n2 = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	size_str = (n < 0) ? 2 : 1;
	while ((n2 /= 10))
		size_str++;
	if (!(str = (char*)malloc(sizeof(*str) * (size_str + 1))))
		return (NULL);
	str[size_str] = '\0';
	n2 = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	while (--size_str >= 0)
	{
		str[size_str] = n2 % 10 + '0';
		n2 /= 10;
	}
	str[0] = (n < 0) ? '-' : str[0];
	return (str);
}
