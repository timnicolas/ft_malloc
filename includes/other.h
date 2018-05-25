/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:20:14 by tnicolas          #+#    #+#             */
/*   Updated: 2018/05/25 16:20:14 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H

# include <ft_malloc.h>
# include <stdbool.h>
# include <sys/mman.h>

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

t_data				*data = NULL;

void				*alloc_memory(size_t size);

#endif
