/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:59:14 by jabae             #+#    #+#             */
/*   Updated: 2022/01/28 17:10:18 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*storage;
	char				*next_line;
	char				*get_line;
	char				*ptr_newline;
	char				buf[BUFFER_SIZE + 1];
	size_t			buf_len;

	if (fd < 0  || BUFFER_SIZE <= 0)
		return (NULL);

	while((buf_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[buf_len] = '\0';
		storage = ft_strjoin(storage, buf);
		if ((ptr_newline = ft_strchr(storage, '\n')))
		{
			next_line = ft_strdup(ptr_newline + 1);
			get_line = ft_substr(storage, 0, ft_strlen(storage) - ft_strlen(ptr_newline) + 1);
			free(storage);
			storage = next_line;
			return (get_line);
		}
	}
	if (storage != NULL)
	{
		get_line = ft_strdup(storage);
		free(storage);
		storage = NULL;
		return (get_line);
	}
	
	return (NULL);
}
