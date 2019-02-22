#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int f1;
	
	char s1[] = "101   GM\tBuick\t2010\n102   Ford\tLincoln\t2005";
	
	f1 = creat("list1.txt", 0700);
	
	write(f1,s1, strlen(s1)  );
	
	close(f1);

	return 0;
}
