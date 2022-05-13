// #include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

/* <--------------- Mandatory part main ---------------> */

// int main() // 파일로부터
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

int main() // redirection으로부터
{
	int		line;
	char	*ret;

	line = 0;

	while((ret = get_next_line(0)) > 0)
	{
		printf(">%d : %s", line, ret);
		free(ret);
		line++;
	}
	printf("\n->%d : %s", line, ret); // 마지막 (NULL) 출력

	free(ret);

	return 0;
}

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ./get_next_line.c ./get_next_line_utils.c ./main.c
// ./a.out < test_file1.txt

// int main() // stdin으로부터
// {
// 	int		line;
// 	char	*ret;

// 	line = 0;

// 	while((ret = get_next_line(STDIN_FILENO)) > 0)
// 	{
// 		printf(">%d : %s", line, ret);
// 		free(ret);
// 		line++;
// 	}
// 	printf("\n->%d : %s", line, ret); // 마지막 (NULL) 출력

// 	free(ret);

// 	return 0;
// }
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ./get_next_line.c ./get_next_line_utils.c ./main.c
// ./a.out 
// 읽을 문자열 입력 (와일로 걸어놨으므로 crtl+D 눌러야 널 나오고 종료)

/* <--------------- Bonus part main ---------------> */

// int main()
// {
// 	int		fd[3], fd_idx, line;
// 	char	*ret;

// 	fd[0] = open("test_file1.txt", O_RDONLY);
// 	fd[1] = open("test_file2.txt", O_RDONLY);
// 	fd[2] = open("test_file3.txt", O_RDONLY);

// 	fd_idx = 0;
// 	while(fd_idx < 3)
// 	{
// 		line = 0;
// 		while((ret = get_next_line(fd[fd_idx])) > 0)
// 		{
// 			printf(">%d : %s", line, ret);
// 			free(ret);
// 			line++;
// 		}
// 		printf("\n->%d : %s\n", line, ret); // 마지막 (NULL) 출력
// 		free(ret);
// 		close(fd[fd_idx]);
// 		fd_idx++;
// 	}
// 	return 0;
// }
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ./get_next_line_bonus.c ./get_next_line_utils_bonus.c ./main.c
// echo 0123456789 > test_file1.txt // 파일 내용 바꾸기
// ./a.out

// lldb : -g -fsanitize=address // 디버깅
