/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:14:48 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/24 17:57:52 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_H
# define FT_PRINTF_STRUCT_H

# define NB_COLOR 20
# define SIZE_COLOR_NAME 10

typedef unsigned long long	t_ull;
typedef long long			t_ll;

typedef struct				s_color
{
	char					name[SIZE_COLOR_NAME];
	char					color[11];
}							t_color;

typedef union				u_type
{
	long long				d;
	t_ull					u;
	void					*p;
	char					*s;
	unsigned int			c;
	double					f;
	time_t					t;
	int						*n;
}							t_type;

typedef struct				s_flag
{
	int						hashtag;
	int						minus;
	int						plus;
	int						zero;
	int						space;
}							t_flag;

typedef struct				s_arg
{
	char					*str;
	t_type					arg;
	char					height[7];
	char					conv;
	t_flag					flag;
	int						wi;
	int						preci;
	int						cmpt;
}							t_arg;

typedef union				u_f
{
	long					l;
	double					f;
}							t_f;

#endif
