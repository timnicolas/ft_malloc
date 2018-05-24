/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:59:01 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/08 19:29:12 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_strlen.c                                              |
**   |     ft_strlen(25 lines)                                  |
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

size_t		ft_strlen(const char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

/*
**size_t		ft_strlen(const char *str)
**{
**	const char		*char_p;
**	const uint64_t	*long_p;
**	int				i;
**
**	long_p = (const uint64_t*)((uintptr_t)str & ~(sizeof(uint64_t) - 1)) + 1;
**	if ((*(long_p - 1) - MASK01) & ((~*(long_p - 1)) & MASK80))
**	{
**		char_p = str - 1;
**		while (++char_p < (const char*)long_p)
**			if (*char_p == '\0')
**				return (char_p - str);
**	}
**	long_p--;
**	while (++long_p)
**	{
**		if ((*long_p - MASK01) & ((~*long_p) & MASK80))
**		{
**			char_p = (const char*)long_p;
**			i = -1;
**			while (++i < (int)sizeof(uint64_t))
**				if (char_p[i] == '\0')
**					return (char_p - str + i);
**		}
**	}
**	return (0);
**}
*/
