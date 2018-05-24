/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:14:49 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:26 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_convert_base.c                                        |
**   |     ft_convert_base(7 lines)                             |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <libft.h>
#include <stdlib.h>

char		*ft_convert_base(char *n, char *base_in, char *base_out)
{
	long long	int_nb;
	char		*ret;

	int_nb = ft_base_to_int(n, base_in);
	if (!(ret = ft_int_to_base(int_nb, base_out)))
		return (NULL);
	return (ret);
}
