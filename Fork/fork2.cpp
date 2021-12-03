#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    int i;

    fork();
    fork();
    fork();
    printf("pid %d \n", getpid());
    return 0;
}
