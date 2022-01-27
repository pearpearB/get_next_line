/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:59:14 by jabae             #+#    #+#             */
/*   Updated: 2022/01/27 17:03:11 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*storage;
	char				*tmp;
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
			tmp = ft_strdup(ptr_newline + 1);
			get_line = ft_substr(storage, 0, ft_strlen(storage) - ft_strlen(ptr_newline) + 1);
			storage = tmp;
			return (get_line);
		}
	}
	// 마지막 어떻게 처리?
	// 놈 맞춰서 함수 나누기, fd 여러개일 때
	// 여러가지 예외사항(빈 파일, 개행만 있는 파일, fd open limit? buffer_size limit?)
	if (storage != NULL)
	{
		get_line = storage;
		storage = NULL;
		return (get_line);
	}

	return (NULL);
} 
