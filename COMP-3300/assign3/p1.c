#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#define NUMBER_OF_POINTS 100

// global variable
int circle_count = 0;

// Function that generates a double precision number
double random_double()
{
    return random() / ((double) RAND_MAX + 1);  //(double) cast used to get division result to a double
}

// Thread function that generates random points
// and checks if its in the circle (for Monte Carlo technique)
void *thread_calc(void *arg)
{
    // Variable declaration 
    double x,y;         // for cartesian coordinates bounded in the square
    int hit_count;      // tracks # of points generated inside the circle
    
    // loop used to generate points and calculate if its inside the circle
    for(int i = 0 ; i < NUMBER_OF_POINTS ; ++i)
    {   
        // generate random number between -1 and 1 (exlusive)
        x = random_double() * 2.0 - 1.0;
        y = random_double() * 2.0 - 1.0;

        // checks if (x,y) is in the circle
        if( sqrt(x*x + y*y) < 1.0 )
            ++hit_count;        // increment counter if (x,y) in the circle
    }
    circle_count = hit_count;   // set global variable circle_count to hit_count
}

int main()
{
    // Seeds the random number generator so you get different random numbers
    srandom((unsigned)time(NULL));

    // Variables
    pthread_t t;                    // For the single thread (slave)
    struct timespec start, finish;  // time spec used to measure timnes
    double time_taken;              // used to calculate time

    // The use of clock() gave incorrect times with running threads (due to cpu time)
    // and found online that clock_gettime() was much more accurate
    clock_gettime(CLOCK_MONOTONIC, &start);                 // grab time (the start)
    
    pthread_create(&t, NULL, thread_calc, NULL);        // create the slave thread that runs thread_calc
    pthread_join(t, NULL);                              // waits for the thread t to complete

    clock_gettime(CLOCK_MONOTONIC, &finish);                // grab time (the end)
    time_taken = (finish.tv_sec - start.tv_sec);            // get the elapsed time in seconds
    time_taken += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;  // add the nanosecs for more accuracy

    printf("Points: %d\n", NUMBER_OF_POINTS);
    printf("pi estimation: %f\n", 4*(circle_count/(double)NUMBER_OF_POINTS));   // Calculate pi estimation
    printf("Time Taken: %f\n", time_taken);

    return 0;
}