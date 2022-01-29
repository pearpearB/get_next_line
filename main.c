#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int		fd;
	char	*ret;

	fd = open("test.txt", O_RDONLY);

	while((ret = get_next_line(fd)) > 0)
	{
		printf(">>>%s\n", ret);
		free(ret);
	}
	printf("--->%s\n", ret);
	free(ret);

	close(fd);

	close(fd);

	return 0;
}