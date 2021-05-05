#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#define NUMBER_OF_POINTS 1000000
#define NUMBER_OF_SLAVES 100

// global variable
int circle_count = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;       // used for mutex locking

// Function that generates a double precision number
double random_double()
{
    return random() / ((double) RAND_MAX + 1); //(double) cast used to get division result to a double
}

// Thread function that generates random points
// and checks if its in the circle (for Monte Carlo technique)
void *thread_calc(void *arg)
{
    // Variable declaration 
    double x,y;         // for cartesian coordinates bounded in the square
    int hit_count;      // tracks # of points generated inside the circle
    
    // loop used to generate points and calculate if its inside the circle
    for(int i = 0 ; i < NUMBER_OF_POINTS/NUMBER_OF_SLAVES ; ++i)
    {   
        // generate random number between -1 and 1 (exlusive)
        x = random_double() * 2.0 - 1.0;
        y = random_double() * 2.0 - 1.0;
        
        // checks if (x,y) is in the circle
        if( sqrt(x*x + y*y) < 1.0 )
            ++hit_count;        // increment counter if (x,y) in the circle
    }

    // Using mutex lock to prevent run condition
    // when trying to access the global variable
    pthread_mutex_lock(&lock);
    circle_count += hit_count;  // add hit_count onto circle_count
    pthread_mutex_unlock(&lock);
}

int main()
{
    // Seeds the random number generator so you get different random numbers
    srandom((unsigned)time(NULL));
    
    // Variables
    pthread_t t[NUMBER_OF_SLAVES];  // List of threads defined
    struct timespec start, finish;  // time spec used to measure timnes
    double time_taken;              // used to calculate time

    // The use of clock() gave incorrect times with running threads (due to cpu time)
    // and found online that clock_gettime() was much more accurate
    clock_gettime(CLOCK_MONOTONIC, &start);                 // grab time (the start)

    // Start all the threads/slaves
    for(int i = 0 ; i < NUMBER_OF_SLAVES ; ++i)
        pthread_create(&t[i], NULL, thread_calc, NULL); // creates thread and runs the thread_calc routine

    // Waits for all the threads/slaves to finish
    for(int i = 0 ; i < NUMBER_OF_SLAVES ; ++i)
        pthread_join(t[i], NULL);       // waiting for specific thread to finish

    clock_gettime(CLOCK_MONOTONIC, &finish);                // grab time (the end)
    time_taken = (finish.tv_sec - start.tv_sec);            // get the elapsed time in seconds
    time_taken += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;  // add the nanosecs for more accuracy

    pthread_mutex_destroy(&lock);   // destroy mutex lock

    // Outputs
    printf("Points: %d | Slaves: %d\n", NUMBER_OF_POINTS,NUMBER_OF_SLAVES);
    printf("Total hits = %d\n\n", circle_count);
    printf("pi estimation = %f\n", 4*(circle_count/(double)NUMBER_OF_POINTS));      // Calculate pi estimation
    printf("Time Taken: %f\n", time_taken);
    return 0;
}