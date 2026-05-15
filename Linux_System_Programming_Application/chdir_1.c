#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>

int main()
{
    char Path[100];

    getcwd(Path,sizeof(Path));
    printf("Current Directory Name : %s\n",Path);

    chdir("./Data");
    
    getcwd(Path,sizeof(Path));
    printf("Current Directory Name : %s\n",Path);

    
    //open("sync_1.c")

    return 0;
}

// If we change char Path[50] to [100] then it will change the dir;
// But now no error is coming