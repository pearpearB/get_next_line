#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int		fd, line;
	char	*ret;

	fd = open("test.txt", O_RDONLY);

	// close(fd); // unvalid fd 일 때,

	while((ret = get_next_line(fd)) > 0)
	{
		printf(">%d : %s", line, ret);
		free(ret);
		line++;
	}
	printf("\n->%d : %s", line, ret); // (NULL)
	free(ret);

	close(fd);

	return 0;
}

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ./*.c
// lldb : -g -fsanitize=address
