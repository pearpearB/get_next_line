/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:59:14 by jabae             #+#    #+#             */
/*   Updated: 2022/01/23 22:57:08 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // 제출 전 꼭 지우기!

char	*get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	
	printf("%d\n", fd);

	if (fd < 0 || read(fd, buffer, BUFFER_SIZE) == -1 || BUFFER_SIZE <= 0)
		return (NULL);

	printf("%s\n", buffer);

	return 0;
} 