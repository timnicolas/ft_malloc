/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:20:49 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/08 19:18:27 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_check.c                                               |
**   |     ft_checkflag(19 lines)                               |
**   |     ft_checkwidth2(18 lines)                             |
**   |     ft_checkwidth(20 lines)                              |
**   |     ft_checkprecision(19 lines)                          |
**   |     ft_check(18 lines)                                   |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_checkflag(t_arg *arg, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '+')
			arg->flag.plus = 1;
		else if (str[i] == '#')
			arg->flag.hashtag = 1;
		else if (str[i] == '-')
			arg->flag.minus = 1;
		else if (str[i] == ' ')
			arg->flag.space = 1;
		else if ((str[i] == '0' && i == 0) ||
				(str[i] == '0' && (str[i - 1] < '0' || str[i - 1] > '9') &&
				str[i - 1] != '.' && str[i - 1] != '*'))
			arg->flag.zero = 1;
	}
	return (SUCCESS);
}

static int	ft_checkwidth2(t_arg *arg, char *str, int *i)
{
	if ((*i == 0) || (!ft_isdigit(str[*i - 1]) && ((str[*i - 1] != '*' &&
						str[*i - 1] != '.') || (*i == 1 && str[*i - 1] != '.')
					|| (*i >= 2 && str[*i - 1] == '*' && str[*i - 2] != '.'))))
	{
		arg->wi = ft_atoi(str + *i);
		return (1);
	}
	else if (ft_isdigit(str[*i - 1]))
	{
		while (*i >= 1 && ft_isdigit(str[*i - 1]))
			--(*i);
		if (*i == 0 || str[*i - 1] != '.')
		{
			arg->wi = ft_atoi(str + *i);
			return (1);
		}
	}
	return (0);
}

static int	ft_checkwidth(t_arg *arg, char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (--i >= 0)
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			if (ft_checkwidth2(arg, str, &i) == 1)
				break ;
		}
		else if (i >= 1 && str[i] == '0' && str[i - 1] == '*')
		{
			if (!(i >= 2 && str[i - 2] == '.'))
			{
				arg->wi = ft_atoi((str + i));
				break ;
			}
		}
	}
	return (SUCCESS);
}

static int	ft_checkprecision(t_arg *arg, char *str)
{
	int		i;

	i = ft_strlen(str);
	while (--i >= 0)
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == '*')
				++i;
			if (str[++i] >= '0' && str[i] <= '9')
				arg->preci = ft_atoi((str + i));
			else if (str[i] == '*')
				arg->preci = -1;
			else
				arg->preci = 0;
			break ;
		}
	}
	return (SUCCESS);
}

int			ft_check(char **ret, char *str, va_list ap, t_arg *arg)
{
	ft_initarg(arg);
	if (str != NULL)
		free(arg->str);
	arg->str = str;
	if (ft_cleanstars(&str, ap) == ERROR && ft_free(1, str))
		return (ERROR);
	if (ft_checkflag(arg, str) == ERROR && ft_free(1, str))
		return (ERROR);
	if (ft_checkwidth(arg, str) == ERROR && ft_free(1, str))
		return (ERROR);
	if (ft_checkprecision(arg, str) == ERROR && ft_free(1, str))
		return (ERROR);
	if (!(arg->str = ft_strdup(str)) && ft_free(2, str, arg->str))
		return (ERROR);
	if (ft_checkconv(ret, arg, ap) == ERROR && ft_free(2, str, arg->str))
		return (ERROR);
	ft_free(2, arg->str, str);
	return (SUCCESS);
}
