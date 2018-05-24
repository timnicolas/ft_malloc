/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:12:36 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:05 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_color.c                                               |
**   |     ft_evalstr(11 lines)                                 |
**   |     ft_put_color(17 lines)                               |
**   |     ft_isignore(11 lines)                                |
**   |     ft_color(25 lines)                                   |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_evalstr(t_color *color, char *str, size_t n)
{
	int		i;

	if (n > SIZE_COLOR_NAME)
		return (-1);
	i = -1;
	while (++i < NB_COLOR)
	{
		if (ft_strncmp(color[i].name, str, n) == 0)
			return (i);
	}
	return (-1);
}

static int	ft_put_color(t_color *color, char **str, long long pl_numc,
		t_arg *arg)
{
	int		size_del;
	int		size_add;
	char	*new_str;

	size_del = ft_strlen(color[ft_get2arg(pl_numc, 1)].name) + 2;
	size_add = ft_strlen(color[ft_get2arg(pl_numc, 1)].color);
	if (!(new_str = malloc(sizeof(char) * (ft_strlen(*str) + size_add - size_del
						+ 1))))
		return (ERROR);
	ft_strncpy(new_str, *str, ft_get2arg(pl_numc, 0));
	new_str[ft_get2arg(pl_numc, 0)] = '\0';
	ft_strncat(new_str, color[ft_get2arg(pl_numc, 1)].color, size_add);
	ft_strcat(new_str, (*str + ft_get2arg(pl_numc, 0) + size_del));
	free(*str);
	*str = new_str;
	arg->cmpt = arg->cmpt + size_add - size_del;
	return (SUCCESS);
}

static int	ft_isignore(char **str, int i)
{
	if (i == 0)
		return (0);
	if ((*str)[i - 1] == '%')
	{
		ft_memmove((*str + i - 1), (*str + i), ft_strlen(*str + i));
		if (!(*str = ft_realloc(*str, (ft_strlen(*str) + 2),
						ft_strlen(*str) + 1)))
			return (-1);
		return (1);
	}
	return (0);
}

int			ft_color(char **str, t_arg *arg)
{
	t_color	color[NB_COLOR];
	int		i[2];
	int		num_c;
	int		ret;

	ft_init_color((i[0] = -1) ? color : color);
	while (++(i[0]) < arg->cmpt)
		if ((*str)[i[0]] == '{' && !(i[1] = 0) && ++(i[0]))
		{
			if ((ret = ft_isignore(str, i[0] - 1)) == 1 || ret == -1)
			{
				if (ret == -1)
					return (ERROR);
			}
			while (ret != 1 && (*str)[i[0] + ++(i[1])])
				if ((*str)[i[0] + i[1]] == '}')
				{
					if ((num_c = ft_evalstr(color, (*str + i[0]), i[1])) != -1)
						if (ft_put_color(color, str, ft_2arg(i[0] - 1, num_c),
									arg) == ERROR)
							return (ERROR);
					break ;
				}
		}
	return (SUCCESS);
}
