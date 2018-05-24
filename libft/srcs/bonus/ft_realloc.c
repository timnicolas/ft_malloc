/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:15:39 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:26 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_realloc.c                                             |
**   |     ft_realloc(17 lines)                                 |
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

void		*ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*new;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
		return (malloc(new_size));
	if ((new = malloc(new_size)) == NULL)
		return (NULL);
	if (new_size < original_size)
		ft_memcpy(new, ptr, new_size);
	else
		ft_memcpy(new, ptr, original_size);
	free(ptr);
	return (new);
}
