/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 18:41:32 by tnicolas          #+#    #+#             */
/*   Updated: 2018/06/01 18:41:32 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

void		*calloc(size_t count, size_t size)
{
	void	*ptr;
	int		total_sz;
	int		i;

	if (!(ptr = malloc(count * size)))
		return (NULL);
	total_sz = (((count * size) - 1) >> 3) + 1;
	i = -1;
	while (++i < total_sz)
		((int64_t*)ptr)[i] = 0;
	return (ptr);
}
