/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:51:53 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/09 12:30:54 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_memcpy.c                                              |
**   |     ft_memcpy(19 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)dst + i) = *((const char *)src + i);
		i++;
	}
	return (dst);
}

/*
**void		*ft_memcpy(void *dst, const void *src, size_t n)
**{
**	const uint64_t	*long_src;
**	uint64_t		*long_dst;
**	int				i;
**
**	if (n == 0)
**		return (dst);
**	long_dst = (uint64_t*)((uintptr_t)dst & ~(sizeof(uint64_t) - 1)) + 1;
**	long_src = (const uint64_t*)((uintptr_t)src & ~(sizeof(uint64_t) - 1)) + 1;
**	i = -1;
**	while (&(src[++i]) < (void*)long_src && (size_t)i < n)
**		((char*)dst)[i] = ((char*)src)[i];
**	long_src--;
**	long_dst--;
**	while (++long_dst && ++long_src && (size_t)(i += 8) < n)
**		*long_dst = *long_src;
**	i -= 9;
**	while ((size_t)++i < n)
**		((char*)dst)[i] = ((char*)src)[i];
**	return (dst);
**}
*/
