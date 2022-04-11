/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:34:14 by jabae             #+#    #+#             */
/*   Updated: 2022/04/11 17:59:44 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	{
		return (split_line(storage));
	}
	else
	{
		if (**storage != '\0')
			last_line = ft_strdup(*storage);
		else
			last_line = NULL;
		free(*storage);
		*storage = NULL;
		return (last_line);
	}
}

static char	*is_error(char *buf)
{
	free(buf);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*buf;
	int			buf_len;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buf_len = read(fd, buf, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE < 1 || !buf)
		return (is_error(buf));
	while (buf_len > 0)
	{
		buf[buf_len] = '\0';
		storage[fd] = ft_strjoin(storage[fd], buf);
		if (ft_strchr(storage[fd], '\n'))
		{
			free(buf);
			return (split_line(&storage[fd]));
		}
		buf_len = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (buf_len == 0 && storage[fd])
		return (read_last(&storage[fd]));
	return (NULL);
}
