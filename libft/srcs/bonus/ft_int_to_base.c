/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:45:01 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:26 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_int_to_base.c                                         |
**   |     ft_int_to_base(19 lines)                             |
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

char		*ft_int_to_base(long long n, char *base)
{
	char				*ret;
	int					size;
	unsigned long long	un;

	un = (n < 0) ? (unsigned long long)-n : (unsigned long long)n;
	size = (n < 0) ? 2 : 1;
	while ((un /= ft_strlen(base)))
		size++;
	if (!(ret = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[0] = (n == 0) ? '0' : '-';
	ret[size] = '\0';
	un = (n < 0) ? (unsigned long long)-n : (unsigned long long)n;
	while (un)
	{
		ret[--size] = base[un % ft_strlen(base)];
		un /= ft_strlen(base);
	}
	return (ret);
}
