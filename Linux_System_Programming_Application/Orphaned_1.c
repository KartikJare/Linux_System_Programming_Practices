// Output depends on scheduling

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    __pid_t pid = 0;

    pid = fork();

    if(pid == 0)    //Child
    {
        printf("Child process is running...\n");
        printf("PID of child is : %d & PIID of child is : %d\n",getpid(),getppid());
    }
    else            // Parent 
    {
        printf("Parent process is running....\n");
        printf("PID of Parent is : %d & PIID of parent is : %d\n",getpid(),getppid());
    }

    return 0 ;
}