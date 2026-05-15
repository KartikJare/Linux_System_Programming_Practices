#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    __pid_t childpid = 0;
    __pid_t ret = 0;
    int status = 0;

    childpid = fork();

    if(childpid == 0)
    {
        printf("Child is running with PID : %d\n",getpid());
        sleep(10);
        printf("Child process exiting\n");
        exit(11);
    }
    else
    {
        printf("Parnet is running\n");

        printf("Parent is waiting for child : %d\n",childpid);

        ret = waitpid(childpid,&status,0);

        if(WIFEXITED(status))
        {
            printf("Child exited with PD : %d\n",ret);
            printf("Exit Status of child is : %d\n",WEXITSTATUS(status));
        }
    }

    return 0;
}