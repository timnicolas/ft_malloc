/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:13:33 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:05 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_checkconv.c                                           |
**   |     ft_tej(20 lines)                                     |
**   |     ft_check_error_height(9 lines)                       |
**   |     ft_checkconv(15 lines)                               |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

int			ft_tej(t_arg *arg, char *str)
{
	int		i;
	int		j;
	int		count_l;
	int		count_h;

	i = -1;
	j = 0;
	count_l = 0;
	count_h = 0;
	ft_memset(arg->height, '\0', 7);
	while (str[++i] && j < 7)
	{
		if (ft_strchr("zj", str[i]))
			arg->height[j++] = str[i];
		else if (ft_strchr("l", str[i]) && count_l < 2 && ++count_l)
			arg->height[j++] = str[i];
		else if (ft_strchr("h", str[i]) && count_h < 2 && ++count_h)
			arg->height[j++] = str[i];
	}
	return (SUCCESS);
}

static int	ft_check_error_height(t_arg *arg)
{
	if (((ft_strchr(arg->height, 'j') || ft_strchr(arg->height, 'z') ||
			(ft_strchr(arg->height, 'l') && ft_strchr(arg->height, 'h')))
			&& (arg->conv != 'c' && arg->conv != 's'))
			|| ft_strchr(&(arg->conv), 'O'))
	{
		ft_memset(arg->height, '\0', 7);
		arg->height[0] = 'j';
	}
	return (SUCCESS);
}

int			ft_checkconv(char **ret, t_arg *arg, va_list ap)
{
	int		i;

	if (ft_tej(arg, arg->str) == ERROR)
		return (ERROR);
	i = -1;
	while (arg->str[++i])
		;
	arg->conv = arg->str[i - 1];
	if (ft_check_error_flag(arg) == ERROR)
		return (ERROR);
	if (ft_check_error_height(arg) == ERROR)
		return (ERROR);
	if (ft_forest(ret, arg, ap) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
