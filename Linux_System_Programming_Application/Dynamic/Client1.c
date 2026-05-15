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

// gcc -fPIC -shared -o Client1.so Client1.c
// gcc -fPIC -shared -o libClient1.so Client1.c