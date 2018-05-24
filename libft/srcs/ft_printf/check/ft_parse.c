/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:50:09 by tnicolas          #+#    #+#             */
/*   Updated: 2018/02/08 19:18:28 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_parse.c                                               |
**   |     ft_isexpr(3 lines)                                   |
**   |     ft_sz_expr(14 lines)                                 |
**   |     ft_norminette(6 lines)                               |
**   |     ft_cest_chiant(10 lines)                             |
**   |     ft_parse(25 lines)                                   |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_isexpr(char c)
{
	if (ft_strchr("+- 0#123456789.*lhzjtq", c) != NULL)
		return (1);
	return (0);
}

static int	ft_sz_expr(const char *format, int i, char **expr)
{
	int		start;
	int		nbchar;

	start = i;
	nbchar = 1;
	while (ft_isexpr(format[i]) == 1 && format[i] != '\0')
	{
		i++;
		nbchar++;
	}
	if (format[i] == '\0')
		return (-i);
	*expr = ft_strsub(format, start, nbchar);
	return (nbchar);
}

static int	ft_norminette(char **ret, t_arg *arg, int x)
{
	if (ft_strcmp(*ret, "") == 0 && ft_free(1, *ret))
		return (ERROR);
	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		write(STDOUT_FILENO, *ret, arg->cmpt - x);
	free(*ret);
	return (ERROR);
}

static int	ft_cest_chiant(int *i, const char *format, char **ret, t_arg *arg)
{
	char	*tmp;

	if ((tmp = ft_strsub(format, *i, 1)) == NULL)
		return (ERROR);
	if ((*ret = ft_strfreejoin(*ret, tmp, 1, arg)) == NULL)
		return (ERROR);
	(arg->cmpt)++;
	++(*i);
	free(tmp);
	return (SUCCESS);
}

int			ft_parse(char **ret, const char *format, va_list ap, t_arg *arg)
{
	static int	i = 0;
	static int	x = 0;
	char		*expr;
	int			nbchar;

	nbchar = ((i *= 0) && (x *= 0)) ? 1 : 1;
	if (!(*ret = ft_strnew(0)))
		return (ERROR);
	while (format[i] && i < (int)ft_strlen(format))
	{
		if (format[i] == '%' && ++i)
		{
			nbchar = ft_sz_expr(format, i, &expr);
			if (nbchar <= 0 && ((i += -nbchar) ? 1 : 1))
				continue;
			if (ft_check(ret, expr, ap, arg) == ERROR)
				return (ft_norminette(ret, arg, x));
			x = ((i += nbchar) && (nbchar -= nbchar - 1)) ? 0 : 0;
		}
		else if (i < (int)ft_strlen(format))
			if (++x && ft_cest_chiant(&i, format, ret, arg) == ERROR)
				return (ERROR);
	}
	return (SUCCESS);
}
