#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd = 0;
    char Buffer[] = "indiaismycountry";
    int iRet = 0;

    fd = open("Demo.txt",O_WRONLY | O_APPEND);

    if(fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reson : %s\n",strerror(errno));
        return -1;
    }

    printf("File Succesfully opened with fb : %d\n",fd);

    iRet = write(fd,Buffer,16); // Overwritten issue

    printf("%d bytes get succesfully wrttien\n",iRet);

    close(fd);

    return 0;
}