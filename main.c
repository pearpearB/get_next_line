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
		printf("%s", ret);
	}
	printf("%s", ret);

	return 0;
}