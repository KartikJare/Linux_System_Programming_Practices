#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void fun()
{
    printf("Inside fun\n");    // inter call here exit (predict the out)
}

void gun()
{
    printf("Inside gun\n");
}

int main()
{
    printf("Prcocess is created\n");

    atexit(fun);
    atexit(gun);

    exit(11);  
}