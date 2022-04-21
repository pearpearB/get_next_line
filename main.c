#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/* <--------------- Mandatory part main ---------------> */

// int main()
// {
// 	int		fd, line;
// 	char	*ret;

// 	fd = open("test_file1.txt", O_RDONLY);
// 	line = 0;

// 	// close(fd); // unvalid fd 일 때,

// 	while((ret = get_next_line(fd)) > 0)
// 	{
// 		printf(">%d : %s", line, ret);
// 		free(ret);
// 		line++;
// 	}
// 	printf("\n->%d : %s", line, ret); // 마지막 (NULL) 출력

// 	free(ret);
// 	close(fd);

// 	return 0;
// }

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ./get_next_line.c ./get_next_line_utils.c ./main.c

/* <--------------- Bonus part main ---------------> */

int main()
{
	int		fd[3], fd_idx, line;
	char	*ret;

	fd[0] = open("test_file1.txt", O_RDONLY);
	fd[1] = open("test_file2.txt", O_RDONLY);
	fd[2] = open("test_file3.txt", O_RDONLY);

	fd_idx = 0;
	while(fd_idx < 3)
	{
		line = 0;
		while((ret = get_next_line(fd[fd_idx])) > 0)
		{
			printf(">%d : %s", line, ret);
			free(ret);
			line++;
		}
		printf("\n->%d : %s\n", line, ret); // 마지막 (NULL) 출력
		free(ret);
		close(fd[fd_idx]);
		fd_idx++;
	}
	return 0;
}

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ./get_next_line_bonus.c ./get_next_line_utils_bonus.c ./main.c
// lldb : -g -fsanitize=address