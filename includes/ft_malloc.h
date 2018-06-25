/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:08:39 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/31 17:41:32 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/mman.h>
# include "../libft/includes/libft.h"

# define SUCCESS 0
# define ERROR   1

/*
**	size max = max size of tiny and small allocation
*/
# define SIZE_MAX_TINY  256
# define SIZE_MAX_SMALL 4096

/*
**	size alloc = SIZE_ALLOC * getpagesize(); (4096)
*/
# define SIZE_ALLOC_TINY  ((size_t)(8 * getpagesize()))
# define SIZE_ALLOC_SMALL ((size_t)(100 * getpagesize()))

/*
**	type of allocation (used in function alloc little)
*/
enum				e_type_alloc
{
	TYPE_TINY, TYPE_SMALL, TYPE_LARGE
};

/*
**	info before a malloc:
**		size of the current malloc
**		ptr to the next malloc
**		free (true if it's free)
*/
typedef struct		s_info
{
	struct s_info	*next;
	struct s_info	*prev;
	size_t			size;
	size_t			official_size;
	bool			free;
	bool			first_in_block;
}					t_info;

/*
**	global variable g_data is used to save pointers from malloc
*/
typedef struct		s_data
{
	void			*ptr_tiny;
	size_t			size_tiny;
	void			*ptr_small;
	size_t			size_small;
	void			*ptr_large;
}					t_data;

extern t_data		*g_data;

size_t				align(size_t size);
void				init_info_alloc(t_info *info, t_info *prev, size_t size);
void				*alloc_little(size_t size, enum e_type_alloc type);
void				*alloc_large(size_t size);
void				*alloc_memory(size_t size);

void				*malloc(size_t size);
void				*calloc(size_t count, size_t size);
void				*realloc(void *ptr, size_t size);
void				free(void *ptr);
int					is_allocated(void *ptr);
size_t				get_alloc_size(void *ptr);
void				print_alloc_mem(void *ptr, size_t size);
void				free_all(void);
void				show_alloc_mem(void);

#endif
