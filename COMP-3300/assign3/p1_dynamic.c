#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

// global variable
int circle_count = 0;
int num_of_pts;

double random_double()
{
    return random() / ((double) RAND_MAX + 1);
}

void *thread_calc(void *arg)
{
    double x,y;
    int hit_count;
    
    for(int i = 0 ; i < num_of_pts ; ++i)
    {
        x = random_double() * 2.0 - 1.0;
        y = random_double() * 2.0 - 1.0;
        if( sqrt(x*x + y*y) < 1.0 )
            ++hit_count;
    }
    circle_count = hit_count;
}

int main()
{
    srandom((unsigned)time(NULL));
    pthread_t t;
    double pi_est;

    printf("Number of Points: ");
    scanf("%d", &num_of_pts);

    clock_t timer = clock();
    pthread_create(&t, NULL, thread_calc, NULL);
    pthread_join(t, NULL);
    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;

    printf("pi estimation = %f\n", 4*(circle_count/(double)num_of_pts));
    printf("Time Taken: %f\n", time_taken);

    return 0;
}