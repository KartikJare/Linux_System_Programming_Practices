#include<stdio.h>

int Addition(int No1,int No2)
{
    int Ans = 0;

    Ans = No1 + No2;

    return Ans;
}    

int main()
{
    int iRet = 0,a = 0,b = 0;

    printf("Enter frist number :\n");
    scanf("%d",&a);

    printf("Enter second number :\n");
    scanf("%d",&b);

    iRet = Addition(a,b);

    printf("Addition is : %d\n",iRet);

    return 0;
}


// gcc debug1.c -o Myexe -g
// gdb ./Myexe
// next,run,quit,print,break,step