/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:26:26 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/08 19:30:58 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_memset.c                                              |
**   |     ft_memset(21 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <libft.h>
#include <stdint.h>

void		*ft_memset(void *b, int c, size_t len)
{
	int		i;

	i = -1;
	while (++i < (int)len)
		((char*)b)[i] = (unsigned char)c;
	return (b);
}

/*
**void		*ft_memset(void *b, int c, size_t len)
**{
**	uint64_t	*long_p;
**	int			i;
**	uint64_t	c8;
**
**	if (len == 0)
**		return (b);
**	c8 = (uint64_t)(c & 0xff) + ((uint64_t)(c & 0xff) << 8) +
**		((uint64_t)(c & 0xff) << 16) + ((uint64_t)(c & 0xff) << 24) +
**		((uint64_t)(c & 0xff) << 32) + ((uint64_t)(c & 0xff) << 40) +
**		((uint64_t)(c & 0xff) << 48) + ((uint64_t)(c & 0xff) << 56);
**	long_p = (uint64_t*)((uintptr_t)b & ~(sizeof(uint64_t) - 1)) + 1;
**	i = -1;
**	while (&(b[++i]) < (void*)long_p && (size_t)i < len)
**		((char*)b)[i] = c;
**	long_p--;
**	while (++long_p && (size_t)(i += 8) < len)
**		*long_p = c8;
**	i -= 9;
**	while ((size_t)++i < len)
**		((char*)b)[i] = c;
**	return (b);
**}
*/
