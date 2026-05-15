#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
    int iRet = 0;

    unlink("output.txt");

    if(iRet == 0)
    {
        printf("Unlink is sucessful\n");
    }

    return 0;
}
