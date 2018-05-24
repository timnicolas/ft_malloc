/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:25:00 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:06 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_conv_s.c                                              |
**   |     ft_strncpy_custom(24 lines)                          |
**   |     ft_check_size(25 lines)                              |
**   |     ft_add_conv_s(25 lines)                              |
**   |     ft_conv_s(5 lines)                                   |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

char	*ft_strncpy_custom(char *tmp, t_arg *arg, size_t n, size_t *i)
{
	int		k;
	int		len;
	char	*ifnull;

	len = (arg->arg.s != NULL ? ft_strlen(arg->arg.s) : 6);
	k = -1;
	if ((arg->flag).minus == 0 && arg->preci != -1 && arg->preci <= len)
		if (arg->wi >= len || arg->preci <= arg->wi)
			*i = arg->wi - arg->preci;
	if ((arg->flag).minus == 0 && arg->preci != -1 && arg->preci > len)
		*i = (arg->wi < len ? 0 : arg->wi - len);
	else if ((arg->flag).minus == 0 && arg->preci == -1 && arg->wi >= len)
		*i = arg->wi - len;
	if (arg->arg.s != NULL)
		while (arg->arg.s[++k] && n--)
			tmp[(*i)++] = arg->arg.s[k];
	else
	{
		ifnull = ft_strdup("(null)");
		while (ifnull[++k] && n--)
			tmp[(*i)++] = ifnull[k];
		free(ifnull);
	}
	return (tmp);
}

void	ft_check_size(t_arg *arg, int *size, int len)
{
	if (arg->wi != 0 && arg->preci != -1)
	{
		if (arg->wi < arg->preci)
		{
			if (arg->preci < len)
				*size = arg->preci;
			else if (len > arg->wi)
				*size = len;
			else
				*size = arg->wi;
		}
		else
			*size = arg->wi;
	}
	else if (arg->wi != 0 && arg->preci == -1)
		*size = (arg->wi < len ? len : arg->wi);
	else if (arg->wi == 0 && arg->preci != -1)
	{
		if (arg->preci == 0)
			*size = 0;
		else if (arg->preci < len)
			*size = arg->preci;
		else
			*size = len;
	}
}

int		ft_add_conv_s(char **ret, t_arg *arg)
{
	char	*tmp;
	int		size;
	size_t	i;
	int		len;

	i = 0;
	if (arg->arg.s != NULL)
		len = ft_strlen(arg->arg.s);
	else
		len = 6;
	size = len;
	ft_check_size(arg, &size, len);
	if (!(tmp = ft_strnew(size)))
		return (ERROR);
	ft_memset(tmp, ' ', size);
	if (arg->flag.zero == 1 && arg->flag.minus == 0)
		ft_memset(tmp, '0', size);
	if (arg->preci != -1)
		len = arg->preci;
	tmp = ft_strncpy_custom(tmp, arg, len, &i);
	if (!(*ret = ft_strfreejoin(*ret, tmp, size, arg)))
		return (ERROR);
	arg->cmpt += size;
	free(tmp);
	return (SUCCESS);
}

int		ft_conv_s(char **ret, t_arg *arg)
{
	if (arg->conv == 'S' || (arg->conv == 's' && ft_length_cs(arg) == ERROR))
		return (ft_init_conv_bigs(ret, arg));
	else if (arg->conv == 's')
		return (ft_add_conv_s(ret, arg));
	return (ERROR);
}
