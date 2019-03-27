#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd;
	int n1 = 101;
	
	fd = open("list1.txt", O_WRONLY);
	write(fd, &n1, 4);
	
	close(fd);


	return 0;
}
