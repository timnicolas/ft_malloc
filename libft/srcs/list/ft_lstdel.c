/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:41:54 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:29 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_lstdel.c                                              |
**   |     ft_lstdel(19 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <stdlib.h>
#include <libft.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;
	t_list		*free_list;

	if (*alst != NULL)
	{
		list = *alst;
		while (list->next)
		{
			del(list->content, list->content_size);
			free_list = list;
			list = list->next;
			free(free_list);
			free_list = NULL;
		}
		del(list->content, list->content_size);
		free(list);
		list = NULL;
		*alst = NULL;
	}
}
