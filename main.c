#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int		fd;
	int		i;
	char	*ret;

	fd = open("test.txt", O_RDONLY);

	while((ret = get_next_line(fd)) > 0)
	{
		printf(">%d : %s", i, ret);
		free(ret);
		i++;
	}
	printf("\n->%d : %s", i, ret);
	free(ret);

	close(fd);

	return 0;
}