#include<stdio.h>
#include<pthread.h>

void * Demo(void *p)    // Call back
{
    printf("Inside Thread with value\n");
    printf("%d\n",*((int*)p+0));
    printf("%d\n",*((int*)p+1));
    printf("%d\n",*((int*)p+2));
    printf("%d\n",*((int*)p+3));
    
    return NULL;
}

int main()
{
    pthread_t TID;
    int iRet = 0;
    int value = 0;
    int Arr[] = {11,21,51,101};

    printf("Main Thread started\n");

    iRet = pthread_create(
                            &TID,        // Thread ID
                            NULL,       // Thread attributes
                            Demo,      // Thread callback function
                            (int *)Arr       // Parameter for th callback function
                        );

    if(iRet == 0)
    {
        printf("Thread gets created succesfully with TID : %lu\n",(unsigned long)TID);
    } 

    // wait
    pthread_join(TID,NULL);

    printf("End of main Thread\n");                    
   
    return 0;
}

// strcut obj 