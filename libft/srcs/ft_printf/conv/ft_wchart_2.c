/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchart_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:06:00 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 13:19:07 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_wchart_2.c                                            |
**   |     ft_tab_s(5 lines)                                    |
**   |     ft_print_oneb(18 lines)                              |
**   |     ft_print_twob(19 lines)                              |
**   |     ft_print_treeb(21 lines)                             |
**   |     ft_print_fourb(23 lines)                             |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static int	ft_tab_s(char **tab, int size, int *i)
{
	*i = 0;
	if (!(*tab = ft_strnew(size)))
		return (ERROR);
	ft_memset(*tab, ' ', size);
	return (SUCCESS);
}

int			ft_print_oneb(char **ret, unsigned int wch, t_arg *arg)
{
	char	*tmp;
	int		i;
	int		taille;

	i = 0;
	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		ft_put_width(&tmp, arg, &i, 1);
	else if (!(tmp = ft_strnew(1)))
		return (ERROR);
	tmp[i] = wch;
	taille = ft_strlen(tmp);
	if (wch == 0)
		taille = 1;
	if (!(*ret = ft_strfreejoin(*ret, tmp, taille, arg)))
		return (ERROR);
	free(tmp);
	arg->cmpt += taille;
	return (SUCCESS);
}

int			ft_print_twob(char **ret, unsigned int wch, t_arg *arg)
{
	unsigned char	ch;
	char			*tab;
	int				i;
	int				taille;

	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		ft_put_width(&tab, arg, &i, 2);
	else
		ft_tab_s(&tab, 2, &i);
	ch = ((wch >> 6) | 0xC0);
	tab[i] = ch;
	ch = ((wch << 26) >> 26 | 0x80);
	tab[i + 1] = ch;
	taille = ft_strlen(tab);
	if (!(*ret = ft_strfreejoin(*ret, tab, taille, arg)))
		return (ERROR);
	arg->cmpt += taille;
	free(tab);
	return (SUCCESS);
}

int			ft_print_treeb(char **ret, unsigned int wch, t_arg *arg)
{
	unsigned char	ch;
	char			*tab;
	int				i;
	int				taille;

	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		ft_put_width(&tab, arg, &i, 3);
	else
		ft_tab_s(&tab, 3, &i);
	ch = ((wch >> 12) | 0xE0);
	tab[i] = ch;
	ch = (((wch >> 6) << 26) >> 26 | 0x80);
	tab[i + 1] = ch;
	ch = ((wch << 26) >> 26 | 0x80);
	tab[i + 2] = ch;
	taille = ft_strlen(tab);
	if (!(*ret = ft_strfreejoin(*ret, tab, taille, arg)))
		return (ERROR);
	arg->cmpt += taille;
	free(tab);
	return (SUCCESS);
}

int			ft_print_fourb(char **ret, unsigned int wch, t_arg *arg)
{
	unsigned char	ch;
	char			*tab;
	int				i;
	int				taille;

	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		ft_put_width(&tab, arg, &i, 4);
	else
		ft_tab_s(&tab, 4, &i);
	ch = (wch >> 18 | 0xF0);
	tab[i] = ch;
	ch = (((wch >> 12) << 26) >> 26 | 0x80);
	tab[i + 1] = ch;
	ch = (((wch >> 6) << 26) >> 26 | 0x80);
	tab[i + 2] = ch;
	ch = (((wch << 26) >> 26) | 0x80);
	tab[i + 3] = ch;
	taille = ft_strlen(tab);
	if (!(*ret = ft_strfreejoin(*ret, tab, taille, arg)))
		return (ERROR);
	arg->cmpt += taille;
	free(tab);
	return (SUCCESS);
}
