#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    // Creates child with fork and store output into pid
    int pid = fork();

    sleep(1);	// Used to sleep for 1 second before zombie creation

    // If fork failed, exit with error code
    if(pid < 0)
        exit(EXIT_FAILURE);	// Exit
    else if(pid != 0)       // if pid != 0 then it is parent processes
      	sleep(10);			// parent sleeps for 10 seconds (zombie alive for ~10s)
    return 0;				// Note: Child will end first (creating a zombie)
}
