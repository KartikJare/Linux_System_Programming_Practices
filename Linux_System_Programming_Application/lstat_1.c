#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
    int iRet = 0;

    struct stat sobj;

    iRet = lstat("./LSPL.txt",&sobj);

    printf("Inode number : %lu\n",sobj.st_ino);
    printf("HardLink count : %lu\n",sobj.st_nlink);
    printf("Total Size : %lu\n",sobj.st_size);
    printf("Block size : %lu\n",sobj.st_blksize);

    printf("File type is : %d\n",sobj.st_mode);
    
    return 0;
}

//fstat at home