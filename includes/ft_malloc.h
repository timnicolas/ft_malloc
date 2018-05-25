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

# include <stdio.h>///////////////
# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/mman.h>
# include <libft.h>

# define SUCCESS 0
# define ERROR   1

/*
**	size max = max size of tiny and small allocation
*/
# define SIZE_MAX_TINY  512
# define SIZE_MAX_SMALL 4096

/*
**	size alloc = SIZE_ALLOC * getpagesize(); (4096)
*/
# define SIZE_ALLOC_TINY  4
# define SIZE_ALLOC_SMALL 16

/*
**	info before a malloc:
**		size of the current malloc
**		ptr to the next malloc
**		free (true if it's free)
*/
typedef struct		s_info
{
	size_t			size;
	struct s_info	*next;
	bool			free;
}					t_info;

/*
**	global variable data is used to save pointers from malloc
*/
typedef struct		s_data
{
	void			*ptr_tiny;
	size_t			size_tiny;
	void			*ptr_small;
	size_t			size_small;
	void			*ptr_large;
}					t_data;

void				*alloc_memory(size_t size);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				free(void *ptr);
void				show_alloc_mem();

#endif
