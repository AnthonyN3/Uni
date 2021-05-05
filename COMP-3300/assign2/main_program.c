#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    system("gcc -o zombie.out make_zombie.c");   // compile the zombie C file and name it zombie

    printf("\n*****Before Zombie Creation*****\n");
    system("./zombie.out &");   // Run the program in #1 (Create a zombie process)
    system("ps -l");            // Display active processes in "Long" format
    sleep(1);                   // Re-sync with zombie.out

    printf("\n*****After Zombie Creation*****\n");
    system("ps -l");            // Display active processes in "Long" format 
    system("kill -9 $(ps -o ppid,stat | grep -w 'Z' | sed 's/^ *//g' | cut -d ' ' -f1 | xargs)"); // Kills all parents of a zombie child

    printf("\n*****After Slaughtering The Zombie(s)*****\n");
    system("ps -l");            // Display active processes in "Long" format

    return 0;
}
