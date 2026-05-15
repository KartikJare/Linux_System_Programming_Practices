#include<stdio.h>
#include<unistd.h>

int main()
{
    __pid_t pid = 0;

    pid = fork();

    if(pid == 0)
    {
        printf("CHILD SAYS : PID of current process : %d ,PID of parent : %d ,Return value of Fork : %d\n",getpid(),getppid(),pid);
        execl("./CommandExe","",NULL);
    }
    else
    {
        printf("PARENT SAYS :PID of current process : %d ,PID of parent : %d ,Return value of Fork : %d\n",getpid(),getppid(),pid);
    }

    return 0;
}