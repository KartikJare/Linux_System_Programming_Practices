#include <stdio.h>
#include <pthread.h>

int iCnt = 0;

void *Increment(void *arg)
{
    // Cretical section start
    iCnt++;
    // Cretical section end
    printf("%d\n", iCnt);


    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, Increment, NULL);
    
    // Logic the other thread will wait 

    pthread_create(&t2, NULL, Increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

// kartik-ganesh-jare@kartik-ganesh-jare-LOQ-15IRX9:~/Desktop/LSP_Application$ ./Myexe
// 1
// 1
