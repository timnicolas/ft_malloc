/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:55:38 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/24 17:57:32 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_init_color.c                                          |
**   |     ft_init_struct_color(14 lines)                       |
**   |     ft_init_struct_font(14 lines)                        |
**   |     ft_init_color(6 lines)                               |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <ft_printf.h>

static void	ft_init_struct_color(t_color *color)
{
	ft_strcpy(color[1].name, "red");
	ft_strcpy(color[1].color, RED);
	ft_strcpy(color[2].name, "green");
	ft_strcpy(color[2].color, GREEN);
	ft_strcpy(color[3].name, "yellow");
	ft_strcpy(color[3].color, YELLOW);
	ft_strcpy(color[4].name, "blue");
	ft_strcpy(color[4].color, BLUE);
	ft_strcpy(color[5].name, "magenta");
	ft_strcpy(color[5].color, MAGENTA);
	ft_strcpy(color[6].name, "cyan");
	ft_strcpy(color[6].color, CYAN);
	ft_strcpy(color[7].name, "white");
	ft_strcpy(color[7].color, WHITE);
}

static void	ft_init_struct_font(t_color *color)
{
	ft_strcpy(color[8].name, "RED");
	ft_strcpy(color[8].color, F_RED);
	ft_strcpy(color[9].name, "GREEN");
	ft_strcpy(color[9].color, F_GREEN);
	ft_strcpy(color[10].name, "YELLOW");
	ft_strcpy(color[10].color, F_YELLOW);
	ft_strcpy(color[11].name, "BLUE");
	ft_strcpy(color[11].color, F_BLUE);
	ft_strcpy(color[12].name, "MAGENTA");
	ft_strcpy(color[12].color, F_MAGENTA);
	ft_strcpy(color[13].name, "CYAN");
	ft_strcpy(color[13].color, F_CYAN);
	ft_strcpy(color[14].name, "WHITE");
	ft_strcpy(color[14].color, F_WHITE);
}

void		ft_init_color(t_color *color)
{
	ft_strcpy(color[0].name, "eoc");
	ft_strcpy(color[0].color, EOC);
	ft_init_struct_color(color);
	ft_init_struct_font(color);
	ft_strcpy(color[15].name, "clear");
	ft_strcpy(color[15].color, CLEAR);
	ft_strcpy(color[16].name, "bold");
	ft_strcpy(color[16].color, BOLD);
	ft_strcpy(color[17].name, "light");
	ft_strcpy(color[17].color, LIGHT);
	ft_strcpy(color[18].name, "italic");
	ft_strcpy(color[18].color, ITALIC);
	ft_strcpy(color[19].name, "uline");
	ft_strcpy(color[19].color, ULINE);
}
