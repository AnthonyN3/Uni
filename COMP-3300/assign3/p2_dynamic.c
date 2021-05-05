#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

// global variable
int circle_count = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

double random_double()
{
    return random() / ((double) RAND_MAX + 1);
}

void *thread_calc(void *arg)
{
    int points_to_gen = *((int *) arg);
    double x,y;
    int hit_count;
    
    for(int i = 0 ; i < points_to_gen; ++i)
    {
        x = random_double() * 2.0 - 1.0;
        y = random_double() * 2.0 - 1.0;
        if( sqrt(x*x + y*y) < 1.0 )
            ++hit_count;
    }

    pthread_mutex_lock(&lock);
    circle_count += hit_count;
    pthread_mutex_unlock(&lock);
}

int main()
{
    srandom((unsigned)time(NULL));
    int num_of_pts, num_of_slaves;

    printf("Number of Points: ");
    scanf("%d", &num_of_pts);
    printf("Num of Slaves: ");
    scanf("%d", &num_of_slaves);

    if(num_of_slaves > num_of_pts)
    {
        printf("More slaves than points...exiting\n");
        exit(EXIT_FAILURE);
    }

    pthread_t t[num_of_slaves];
    double pi_est;
    int remainder, points, points_plus_1;
    
    remainder = num_of_pts % num_of_slaves;
    points = floor(num_of_pts/num_of_slaves);
    points_plus_1 = points + 1;

    clock_t timer = clock();
    for(int i = 0 ; i < num_of_slaves ; ++i)
    {
        if (i < remainder )
            pthread_create(&t[i], NULL, thread_calc, (void *) &points_plus_1);
        else
            pthread_create(&t[i], NULL, thread_calc, (void *) &points);
    }
    for(int i = 0 ; i < num_of_slaves ; ++i)
        pthread_join(t[i], NULL);
    
    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;

    pthread_mutex_destroy(&lock);

    printf("Total hits = %d\n", circle_count);
    printf("pi estimation = %f\n", 4*(circle_count/(double)num_of_pts));
    printf("Time Taken: %f\n", time_taken);

    return 0;
}