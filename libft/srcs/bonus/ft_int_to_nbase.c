/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_to_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:32:16 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:26 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_int_to_nbase.c                                        |
**   |     ft_int_to_nbase(15 lines)                            |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <libft.h>
#include <stdlib.h>

char		*ft_int_to_nbase(long n, char *base, int size)
{
	char			*ret;
	unsigned long	un;

	un = (n < 0) ? (unsigned long)-n : (unsigned long)n;
	if (!(ret = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size] = '\0';
	while (size > 0)
	{
		ret[--size] = base[un % ft_strlen(base)];
		un /= ft_strlen(base);
	}
	if (n < 0)
		ret[0] = '1';
	return (ret);
}
