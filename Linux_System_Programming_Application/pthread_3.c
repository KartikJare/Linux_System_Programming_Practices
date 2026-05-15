#include<stdio.h>
#include<pthread.h>

void * Demo(void *p)    // Call back
{
    printf("Inside Thread\n");
    return NULL;
}

int main()
{
    pthread_t TID;
    int iRet = 0;

    printf("Main Thread started\n");

    iRet = pthread_create(
                            &TID,    // Thread ID
                            NULL,    // Thread attributes
                            Demo,    // Thread callback function
                            NULL     // Parameter for th callback function
                        );

    if(iRet == 0)
    {
        printf("Thread gets created succesfully\n");
    } 

    // wait
     
    printf("End of main Thread\n");                    
   
    return 0;
}