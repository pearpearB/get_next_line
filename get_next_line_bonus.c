/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:34:14 by jabae             #+#    #+#             */
/*   Updated: 2022/04/13 16:40:37 by jabae            ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	*storage[ARRAY_MAX];
	char		*buf;
	int			read_size;
	int			error_flag;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_size = read(fd, buf, BUFFER_SIZE);
	error_flag = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || !buf)
		error_flag = 1;
	while (read_size > 0 && !error_flag)
	{
		buf[read_size] = '\0';
		storage[fd] = ft_strjoin(storage[fd], buf);
		if (ft_strchr(storage[fd], '\n'))
		{
			free(buf);
			return (split_line(&storage[fd]));
		}
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (read_size == 0 && storage[fd] && !error_flag)
		return (read_last(&storage[fd]));
	return (NULL);
}
