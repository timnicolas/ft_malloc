/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:08:39 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/24 12:08:39 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <libft.h>

void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		free(void *ptr);
void		show_alloc_mem();

#endif
