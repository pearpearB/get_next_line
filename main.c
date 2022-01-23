#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	get_next_line(open("test.txt", O_RDONLY));
	
	return 0;
}