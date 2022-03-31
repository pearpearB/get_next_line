#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int		fd;
	char	*ret;
	int		i = 0;

	fd = open("test.txt", O_RDONLY);

	while((ret = get_next_line(fd)) > 0)
	{
		printf(">%d : %s", i, ret);
		free(ret);
		i++;
	}
	printf("\n->%d : %s", i, ret); // (NULL)
	free(ret);

	close(fd);

	return 0;
}

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ./*.c
