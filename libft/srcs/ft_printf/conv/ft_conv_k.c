/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_k.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:33:05 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:06 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_conv_k.c                                              |
**   |     ft_get_year(21 lines)                                |
**   |     ft_get_day2(22 lines)                                |
**   |     ft_get_day(22 lines)                                 |
**   |     ft_min_sec(21 lines)                                 |
**   |     ft_conv_k(24 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_get_year(char *new, char *tmp, t_arg *arg)
{
	int		i;
	time_t	time;
	int		year;

	time = arg->arg.t;
	time -= 365 * 2;
	year = 1972;
	i = -1;
	while (time > 365 + (++i % 4 == 0) ? 1 : 0)
	{
		++year;
		time -= 365 + ((i % 4 == 0) ? 1 : 0);
	}
	if (!(tmp = ft_itoa(year)))
		return (ERROR);
	new[3] = tmp[3];
	new[2] = tmp[2];
	new[1] = tmp[1];
	new[0] = tmp[0];
	free(tmp);
	return (SUCCESS);
}

static void	ft_get_day2(int i, int *j, time_t *time)
{
	*j = 0;
	while (++*j <= 12)
	{
		if (*j == 4 || *j == 6 || *j == 9 || *j == 11)
		{
			if (*time <= 30)
				break ;
			*time -= 30;
		}
		else if (*j == 2)
		{
			if (*time <= 28 + ((i % 4 == 0) ? 1 : 0))
				break ;
			*time -= 28 + ((i % 4 == 0) ? 1 : 0);
		}
		else
		{
			if (*time <= 31)
				break ;
			*time -= 31;
		}
	}
}

static int	ft_get_day(char *new, char *tmp, t_arg *arg)
{
	int		i;
	int		j;
	time_t	time;

	time = arg->arg.t;
	time -= 365 * 2;
	i = -1;
	while (time > 365 + (++i % 4 == 0) ? 1 : 0)
		time -= 365 + ((i % 4 == 0) ? 1 : 0);
	ft_get_day2(i, &j, &time);
	if (!(tmp = ft_itoa(time + 1)))
		return (ERROR);
	new[9] = (tmp[1] == '\0') ? tmp[0] : tmp[1];
	new[8] = (tmp[1] == '\0') ? '0' : tmp[0];
	free(tmp);
	if (!(tmp = ft_itoa(j)))
		return (ERROR);
	new[6] = (tmp[1] == '\0') ? tmp[0] : tmp[1];
	new[5] = (tmp[1] == '\0') ? '0' : tmp[0];
	free(tmp);
	arg->arg.t -= time;
	return (SUCCESS);
}

static int	ft_min_sec(char **new, t_arg *arg, char *tmp)
{
	if (!((*new) = ft_strdup("1999-04-12 20:30:42")))
		return (ERROR);
	if (!(tmp = ft_itoa(arg->arg.t % 60)))
		return (ERROR);
	(*new)[18] = (tmp[1] == '\0') ? tmp[0] : tmp[1];
	(*new)[17] = (tmp[1] == '\0') ? '0' : tmp[0];
	arg->arg.t /= 60;
	free(tmp);
	if (!(tmp = ft_itoa(arg->arg.t % 60)))
		return (ERROR);
	(*new)[15] = (tmp[1] == '\0') ? tmp[0] : tmp[1];
	(*new)[14] = (tmp[1] == '\0') ? '0' : tmp[0];
	arg->arg.t /= 60;
	free(tmp);
	if (!(tmp = ft_itoa(arg->arg.t % 24 + 1)))
		return (ERROR);
	(*new)[12] = (tmp[1] == '\0') ? tmp[0] : tmp[1];
	(*new)[11] = (tmp[1] == '\0') ? '0' : tmp[0];
	arg->arg.t /= 24;
	free(tmp);
	return (SUCCESS);
}

int			ft_conv_k(char **ret, t_arg *arg)
{
	char	*new;
	char	*tmp;

	tmp = NULL;
	if (arg->conv == 'K')
	{
		if (ft_min_sec(&new, arg, tmp) == ERROR)
			return (ERROR);
	}
	else
	{
		if (!(new = ft_strdup("1999-04-12")))
			return (ERROR);
		arg->arg.t /= 86400;
	}
	if (ft_get_day(new, tmp, arg) == ERROR)
		return (ERROR);
	if (ft_get_year(new, tmp, arg) == ERROR)
		return (ERROR);
	if (!(*ret = ft_strfreejoin(*ret, new, ft_strlen(new), arg)))
		return (ERROR);
	arg->cmpt += ft_strlen(new);
	free(new);
	return (SUCCESS);
}
