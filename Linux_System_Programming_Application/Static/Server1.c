#include<stdio.h>
#include<stdlib.h>

int Addition(int A,int B);
int Substraction(int A,int B);

int main()
{
    int iRet = 0;

    iRet = Addition(11,10);
    printf("Addition is :%d\n",iRet);

    iRet = Substraction(11,10);
    printf("Addition is :%d\n",iRet);

    return 0;
}

// gcc Server1.c -L. libClient1.a -o Server1
// string.h
// math.h
// C -> cpp OOP
// DS project in .os