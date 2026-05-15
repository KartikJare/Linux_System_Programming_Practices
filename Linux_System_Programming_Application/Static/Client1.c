int Addition(int A,int B)
{
    int Ans = 0;
    Ans = A + B;
    return Ans;
}

int Substraction(int A,int B)
{
    int Ans = 0;
    Ans = A -B;
    return Ans;
}

// gcc -c Client1.c -o Client1.o
// ar rcs libClient1.a Client1.o 
// rcs = replace,create,symbol index
// ar = archive utility