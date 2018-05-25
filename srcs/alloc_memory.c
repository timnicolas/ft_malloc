/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:22:06 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/25 18:22:06 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <other.h>

static void	*init_data()
{
	int		size;

	size = sizeof(t_data) +
		SIZE_ALLOC_TINY * getpagesize() +
		SIZE_ALLOC_SMALL * getpagesize() +
		sizeof(t_info);
	printf("%d\n", size);
	data = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
}

void		*alloc_memory(size_t size)
{
	if (data == NULL)
		init_data();
	return (NULL);
}
