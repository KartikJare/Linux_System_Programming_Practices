// argc = 1
//  argv[0]
// ./myexe

// argc = 2
//  argv[0] argv[1]
// ./myexe /home/Demo

// argc = 3
//   argv[0] argv[1]    argv[2]
// ./myexe  /home/Demo  5

//////////////////////////////////////////////////////////////////////////
//
//      header  file inclusion
//
//////////////////////////////////////////////////////////////////////////

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/statvfs.h>

//////////////////////////////////////////////////////////////////////////
//
//      Gobal
//
//////////////////////////////////////////////////////////////////////////

static volatile sig_atomic_t stop_flag = 0;

// ctrl+c handler
static void sigint_handler(int sig)
{
    (void)sig;

    printf("Marvellous System Logger is terminating\n");

    // Tell the thread to stop the execution
    stop_flag = 1;
}

// structure which holds all system information
typedef struct
{
    double cpu;  // CPU usage percentage
    double mem;  // RAM usage percentage
    double disk; // Harddik usage percentage
} Snapshot;

// Golbal object which holds information
static Snapshot snap;

// Mutex lock for critical section
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

// Defeult path for disk
static char *disk_path = "/";

// Sleep timer for log
static int interval_sec = 2;

//////////////////////////////////////////////////////////////////////////
//
//     Helper function definations
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Function to collect CPU information
//////////////////////////////////////////////////////////////////////////

static double cpu_percent()
{
    // Logic to fetch CPU information

    return 0.0;
}

//////////////////////////////////////////////////////////////////////////
// Function to collect memory information
//////////////////////////////////////////////////////////////////////////

static double mem_percent()
{
    // Logic to fetch memory information

    return 0.0;
}

//////////////////////////////////////////////////////////////////////////
// Function to collect Disk information
//////////////////////////////////////////////////////////////////////////

static double disk_percent(char *path)
{
    // Logic to fetch Disk information

    return 0.0;
}

// Thread proc for thread which collects system infromation
static void *collector_thread(void *arg)
{
    double c = 0.0,m = 0.0,d = 0.0;
    
    (void)arg;

    printf("Inside collector thread\n");

    // Enter if ctrl+c is not arrived
    while (!stop_flag)
    {
        // Calculate the current resource usage

        double c = cpu_percent();
        double m = mem_percent();
        double d = disk_percent(disk_path);

        // Strat the critical section
        pthread_mutex_lock(&mtx);

        snap.cpu = c;
        snap.mem = m;
        snap.disk = d;

        // End of critical section
        pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

// Thread proc for thread which write log
static void *logger_thread(void *arg)
{
    double m = 0.0,c = 0.0,d = 0.0;
    
    (void)arg;

    printf("Inside Logger thread\n");

    int fd = 0;
    int i = 0; 

    fd = open("Marvellous_log.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);

    char welcome[] = "Marvellous system Logger";

    write(fd, welcome, strlen(welcome));

    while (!stop_flag)
    {
        pthread_mutex_lock(&mtx);

        d = snap.disk;
        c = snap.cpu;
        m = snap.mem;

        pthread_mutex_unlock(&mtx);

        // Write the information of structure snap into file

        // preapare string using sprintf
        char line[256];

        //writ that sting into log files

        // write(fd,line,strlen(line));

        // // sleep for interval

        // for(i = 0;i < interval_sec && ! stop_flag;i++)
        // {
        //     sleep(1);
        // }
    }

    close(fd);
    return NULL;
}

//////////////////////////////////////////////////////////////////////////
//
//      Entry point function of project
//
//////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
    // ./ myexe /home/Demo
    if (argc == 2)
    {
        disk_path = argv[1];
    }
    // ./myexe /home/Demo 5
    else if (argc == 3)
    {
        disk_path = argv[1];
        interval_sec = atoi(argv[2]);
    }

    printf("Marvellous System Logger\n");

    printf("Path is : %s\n", disk_path);
    printf("Interval is : %d\n", interval_sec);

    // Structure for handling ctrl+c
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));

    sa.sa_handler = sigint_handler;

    sigaction(SIGINT, &sa, NULL);

    // Thread to collect the infromation
    pthread_t t_collect;

    // Thread to write the data into log
    pthread_t t_log;

    // Create thread to collect infromation
    pthread_create(&t_collect, NULL, collector_thread, NULL);

    // Create thread to i write data into log
    pthread_create(&t_log, NULL, logger_thread, NULL);

    // Main thrad Waiting for child threads to terminate
    pthread_join(t_collect, NULL);
    pthread_join(t_log, NULL);

    printf("Terminating the Marvellous System Looger\n");

    return 0;
}


// -Wall to show warning