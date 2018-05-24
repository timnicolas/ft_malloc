/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:28:05 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:06 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_conv_f.c                                              |
**   |     ft_precision_f(18 lines)                             |
**   |     flag_width_f(10 lines)                               |
**   |     right_justify_f(14 lines)                            |
**   |     left_justify_f(17 lines)                             |
**   |     ft_conv_f(16 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

void		ft_precision_f(char *str, int p)
{
	int	i;

	i = 0;
	if (p == 0)
	{
		while (*str != '.')
			++str;
		*str = '\0';
		return ;
	}
	if (p == -1)
		p = 6;
	while (*str != '.')
		++str;
	++str;
	while (i < p)
		++i;
	str[i] = '\0';
}

char		*flag_width_f(char *str, int width)
{
	size_t	s_len;
	size_t	spaces_to_add;

	s_len = ft_strlen(str);
	spaces_to_add = width - s_len;
	if ((str = ft_realloc(str, s_len + 1, s_len + 1 + spaces_to_add)) == NULL)
		return (NULL);
	ft_memmove(str + spaces_to_add, str, s_len + 1);
	ft_memset(str, ' ', spaces_to_add);
	return (str);
}

char		*right_justify_f(char *str, int width)
{
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(str);
	if ((str = ft_realloc(str, s_len + 1, s_len + 1 + (width - s_len))) == NULL)
		return (NULL);
	ft_memmove(str + (width - s_len), str, s_len + 1);
	i = 0;
	while (i < width - s_len)
	{
		str[i] = ' ';
		++i;
	}
	return (str);
}

char		*left_justify_f(char *str, int width)
{
	size_t	s_len;
	size_t	i;
	size_t	j;

	s_len = ft_strlen(str);
	if ((str = ft_realloc(str, s_len + 1, s_len + 1 + (width - s_len))) == NULL)
		return (NULL);
	i = s_len;
	j = 0;
	while (j < width - s_len)
	{
		str[i] = ' ';
		++i;
		++j;
	}
	str[i] = '\0';
	return (str);
}

int			ft_conv_f(char **ret, t_arg *arg)
{
	double	f;
	char	*str;

	f = (arg->arg.f > 0) ? (arg->arg.f) : (-(arg->arg.f));
	if ((str = ft_ftoa(f, (arg->arg.f < 0))) == NULL)
		return (ERROR);
	if (!(str = ft_arrondis_f(str, arg->preci)))
		return (ERROR);
	ft_precision_f(str, arg->preci);
	if (ft_flags_f(&str, (arg->arg.f < 0), arg) == ERROR)
		return (ERROR);
	if ((*ret = ft_strfreejoin(*ret, str, ft_strlen(str), arg)) == NULL)
		return (ERROR);
	arg->cmpt += ft_strlen(str);
	free(str);
	return (SUCCESS);
}
