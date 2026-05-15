#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void *handle = NULL;

    int (*fp)(int , int);

    int iRet = 0;

    handle = dlopen("./libClient1.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    printf("Library gets loaded succesfully\n");

    fp = (int(*)(int,int))dlsym(handle,"Addition");

    if(fp == NULL)
    {
        printf("Unable to get address of function\n");
        dlclose(handle);

        return -1;
    }

    iRet = fp(11,10);

    printf("Addition is : %d\n",iRet);

    fp = (int(*)(int,int))dlsym(handle,"Substraction");

    if(fp == NULL)                                             
    {
        printf("Unable to get address of function\n");
        dlclose(handle);

        return -1;
    }

    iRet = fp(11,10);

    printf("Substraction is : %d\n",iRet);

    dlclose(handle);

    return 0;
}

// gcc Server1.c -o Server1 -ldl
// dlerror -> bring error code