#include<stdio.h>
#include<fcntl.h>

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

    return 0;
}

// Use trunc carefully 

//512
//0x00000200
//0000  0000  0000  0000  0000  0010  0000  0000