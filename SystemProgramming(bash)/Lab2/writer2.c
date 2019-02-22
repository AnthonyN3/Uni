#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
        int f1;

        char s1[] = "GM\t101\tBuick\t2010\nFord\t102\tLincoln\t2005";

        f1 = creat("list2.txt", 0700);

        write(f1,s1, strlen(s1)  );

        close(f1);

        return 0;
}

