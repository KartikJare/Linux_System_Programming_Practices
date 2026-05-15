#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0;

    fd = open("Second.c",O_CREAT | O_TRUNC,0777);

    if(fd == -1)
    {
        printf("Unable to create the file\n");
    }
    else
    {
        printf("File gets sucesfully created with fd : %d\n",fd);
    }

    close(fd);

    return 0;
}