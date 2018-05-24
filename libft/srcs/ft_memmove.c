/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:16:44 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:27 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_memmove.c                                             |
**   |     ft_memmove(20 lines)                                 |
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

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (((unsigned long)src) < ((unsigned long)dst))
	{
		while (len > 0)
		{
			*((char *)(dst + len - 1)) = *((const char *)(src + len - 1));
			--len;
		}
	}
	else if (((unsigned long)src) > ((unsigned long)dst))
	{
		i = 0;
		while (i < len)
		{
			*((char *)(dst + i)) = *((const char *)(src + i));
			++i;
		}
	}
	return (dst);
}
