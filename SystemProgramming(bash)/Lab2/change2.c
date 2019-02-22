#include <unistd.h>
#include <fcntl.h>

int main()
{
        int fd;
        int n1 = 101;

        fd = open("list2.txt", O_WRONLY);
	lseek(fd, 3, SEEK_SET);
	write(fd, &n1, 4);	

        close(fd);


        return 0;
}
