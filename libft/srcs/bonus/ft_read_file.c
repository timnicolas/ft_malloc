/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:46:55 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:41:26 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_read_file.c                                           |
**   |     ft_read_file(18 lines)                               |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

int			ft_read_file(char *filename, char **file_content)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		ret_read;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	if (!(*file_content = malloc(sizeof(**file_content))))
		return (0);
	(*file_content)[0] = '\0';
	while ((ret_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret_read] = '\0';
		*file_content = ft_realloc(*file_content, ft_strlen(*file_content) + 1,
				ft_strlen(*file_content) + ret_read + 1);
		ft_strncat(*file_content, buf, ret_read);
	}
	close(fd);
	return (ft_strlen(*file_content));
}
