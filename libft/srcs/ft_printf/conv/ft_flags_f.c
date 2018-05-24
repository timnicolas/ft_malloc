/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:23:26 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:07 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_flags_f.c                                             |
**   |     flag_space_f(5 lines)                                |
**   |     flag_plus_f(10 lines)                                |
**   |     flag_hashtag_f(11 lines)                             |
**   |     flag_zero_f(21 lines)                                |
**   |     ft_flags_f(23 lines)                                 |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static char	*flag_space_f(char *str)
{
	if ((str = ft_realloc(str, ft_strlen(str) + 1, ft_strlen(str) + 2)) == NULL)
		return (NULL);
	ft_memmove(str + 1, str, ft_strlen(str) + 1);
	str[0] = ' ';
	return (str);
}

static char	*flag_plus_f(char *str, int flag_zero)
{
	if (flag_zero == 1)
	{
		str[0] = '+';
		return (str);
	}
	if ((str = ft_realloc(str, ft_strlen(str) + 1, ft_strlen(str) + 2)) == NULL)
		return (NULL);
	ft_memmove(str + 1, str, ft_strlen(str) + 1);
	str[0] = '+';
	return (str);
}

static char	*flag_hashtag_f(char *str)
{
	size_t	s_len;

	s_len = ft_strlen(str);
	if (ft_strchr(str, '.') == NULL)
	{
		if ((str = ft_realloc(str, s_len + 1, s_len + 2)) == NULL)
			return (NULL);
		str[s_len] = '.';
		str[s_len + 1] = '\0';
	}
	return (str);
}

static char	*flag_zero_f(char *str, int width, int space, t_arg *arg)
{
	size_t	s_len;
	size_t	i;
	size_t	f_zero;

	f_zero = 0;
	s_len = ft_strlen(str);
	if ((str = ft_realloc(str, s_len + 1, s_len + 1 + width - s_len)) == NULL)
		return (NULL);
	ft_memmove(str + width - s_len - space, str, s_len + 1);
	i = 0;
	if (arg->flag.zero == 1 && arg->arg.f < 0)
	{
		str[i++] = '-';
		f_zero = 1;
	}
	while (i < width - s_len - space + f_zero)
	{
		str[i] = '0';
		++i;
	}
	return (str);
}

int			ft_flags_f(char **str, int sign, t_arg *arg)
{
	if (arg->flag.zero == 1 && arg->wi > 0
			&& (size_t)arg->wi > ft_strlen(*str))
		if ((*str = flag_zero_f(*str, arg->wi, arg->flag.space, arg)) == NULL)
			return (ERROR);
	if (arg->flag.plus == 0 && arg->flag.space == 1 && sign == 0)
		if ((*str = flag_space_f(*str)) == NULL)
			return (ERROR);
	if (arg->flag.plus == 1 && arg->arg.f > 0)
		if ((*str = flag_plus_f(*str, arg->flag.zero)) == NULL)
			return (ERROR);
	if ((size_t)arg->wi > ft_strlen(*str) && arg->flag.zero == -1)
		if ((*str = flag_width_f(*str, arg->wi)) == NULL)
			return (ERROR);
	if (arg->flag.hashtag == 1)
		if ((*str = flag_hashtag_f(*str)) == NULL)
			return (ERROR);
	if ((size_t)arg->wi > ft_strlen(*str) && arg->flag.minus == 0)
		if ((*str = right_justify_f(*str, arg->wi)) == NULL)
			return (ERROR);
	if ((size_t)arg->wi > ft_strlen(*str) && arg->flag.minus == 1)
		if ((*str = left_justify_f(*str, arg->wi)) == NULL)
			return (ERROR);
	return (SUCCESS);
}
