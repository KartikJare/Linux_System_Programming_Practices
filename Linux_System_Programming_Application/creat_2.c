#include<stdio.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int fd = 0;

    fd = creat(argv[1],0777);

    if(fd == -1)
    {
        printf("Unable to create the file\n");
    }
    else
    {
        printf("file gets succesfully created with fd : %d\n",fd);
    }
        
    return 0;
}

// > output redirection
// < input redirection
// 2> error redirection