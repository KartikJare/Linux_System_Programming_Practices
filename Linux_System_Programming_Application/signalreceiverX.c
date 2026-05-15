#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void MarvellousHandler(int no) // This take signal number in this case it will come (10)
{
    printf(" Marvellous Message - Signal arrived : %d\n",no);
}

int main()
{
    printf("PID is : %d\n",getpid());

    signal(SIGUSR1,MarvellousHandler);

    while (1)
    {
        sleep(1);
    }
    
    return 0;
}


// Signal hander do not kill the process 
// kill -SIGABRT 136351 to abort