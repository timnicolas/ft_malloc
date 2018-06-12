/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:34:36 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/31 17:41:31 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | realloc.c                                                |
**   |     realloc(3 lines)                                     |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_malloc.h>

static void	*ft_bigger_realloc(void *ptr, size_t size, t_info *inf,
		size_t new_size)
{
	void	*new;

	if (inf->size <= SIZE_MAX_TINY && new_size <= SIZE_MAX_TINY)
	{

	}
	else if (inf->size <= SIZE_MAX_SMALL && new_size <= SIZE_MAX_SMALL)
	{

	}
	if (!(new = malloc(size)))
		return (NULL);
	ft_memcpy(new, ptr, inf->size);
	free(ptr);
	return (new);
}

static void	*ft_smaller_realloc(void *ptr, size_t size, t_info *inf,
		size_t new_size)
{ // check error if we have to change type (small to tiny for example)
	t_info	*new;

	if (inf->size > SIZE_MAX_SMALL)
	{
		inf->official_size = size;
		return (ptr);
	}
	new = (void*)inf + new_size + sizeof(t_info);
	new->next = inf->next;
	if (new->next)
		new->next->prev = new;
	new->prev = inf;
	inf->next = new;
	new->size = inf->size - sizeof(t_info) - new_size;
	new->official_size = new->size;
	inf->size = new_size;
	inf->official_size = size;
	new->free = false;
	new->first_in_block = false;
	free((void*)new + sizeof(t_info));
//	ft_printf("smaller malloc\n");
	return (ptr);
}

void		*realloc(void *ptr, size_t size)
{
	size_t	new_size;
	t_info	*inf;

	if (ptr == NULL)
		return (malloc(size));
 	new_size = align(size);
	inf = (t_info*)(ptr - sizeof(t_info));
	if (inf->size < new_size)
		return (ft_bigger_realloc(ptr, size, inf, new_size));
	else if (inf->size > new_size + sizeof(t_info))
		return (ft_smaller_realloc(ptr, size, inf, new_size));
//	ft_printf("same malloc\n");
	inf->official_size = size;
	return (ptr);
}
