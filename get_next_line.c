/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:59:14 by jabae             #+#    #+#             */
/*   Updated: 2022/01/30 16:14:42 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*split_line(char **storage)
{
	char	*ptr_newline;
	char	*next_line;
	char	*get_line;

	ptr_newline = ft_strchr(*storage, '\n');
	next_line = ft_strdup(ptr_newline + 1);
	get_line = ft_substr(*storage, 0,
			ft_strlen(*storage) - ft_strlen(ptr_newline) + 1);
	free(*storage);
	*storage = next_line;
	return (get_line);
}

static char	*read_last(char	**storage)
{
	char	*last_line;

	if (ft_strchr(*storage, '\n'))
		return (split_line(storage));
	else
	{
		last_line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
		return (last_line);
	}
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buf;
	size_t		buf_len;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0) // OPEN_MAX? 256?
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buf_len = read(fd, buf, BUFFER_SIZE);
	while (buf_len > 0)
	{
		buf[buf_len] = '\0';
		storage = ft_strjoin(storage, buf);
		if (ft_strchr(storage, '\n'))
		{
			free(buf);
			return (split_line(&storage));
		}
		buf_len = read(fd, buf, BUFFER_SIZE); // 개행이 없을 때 계속 붙여나갈 수 있도록
	}
	free(buf);
	if (buf_len == 0 && storage)
		return (read_last(&storage));
	return (NULL);
}
