/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getheight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:41:00 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:07 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_getheight.c                                           |
**   |     ft_getheight(14 lines)                               |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

char		ft_getheight(t_arg *arg)
{
	char	ret;
	int		i;

	ret = 0;
	i = -1;
	while (arg->height[++i])
	{
		ret = (ret == 'h' && arg->height[i] == 'h') ? 'H' : ret;
		ret = (ret == 0 && arg->height[i] == 'h') ? 'h' : ret;
		ret = (ret == 'l' && arg->height[i] == 'l') ? 'L' : ret;
		ret = (ret == 0 && arg->height[i] == 'l') ? 'l' : ret;
		ret = (arg->height[i] == 'j') ? 'L' : ret;
	}
	return (ret);
}
