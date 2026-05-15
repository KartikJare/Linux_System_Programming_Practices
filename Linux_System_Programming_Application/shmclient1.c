#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>

int main()
{
    int id = 0;

    id = shmget(11,1024,0666);

    if(id != -1)
    {
        printf("Share memeory gets allocated by the client\n");
    }

    return 0;
}