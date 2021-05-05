#include <stdio.h>
#define TIME_QUANTUM 2

int main()
{
  int num_proc; // used to store number of processes

  // Prompt for user input for # of processes and stores into num_proc
  printf("Enter number of processes: ");
  scanf("%d", &num_proc);

  // Creates 2 arrays with size corresponding to processes
  // one stores burst time and the other stores a copy to later use for calculation
  int burst_time[num_proc], track_time[num_proc];

  printf("\nEnter burst times for each processes:\n");

  // for loop to get burst time for each process
  for( int i = 0 ; i < num_proc ; ++i)
  {
    int input;

    printf("process %d: ", i+1);
    scanf("%d", &input);

    // checks if user inputs value number (>0)
    if(input > 0)
    {
      // if (>0) then stores burst times in the 2 arrays
      burst_time[i] = input;
      track_time[i] = input;
    }
    else
    {
      printf("Enter value greater than 0\n");
      --i;
    }
  }

  printf("\nTime Quantum: %d\n", TIME_QUANTUM);
  printf("Arrival Time: 0\n");

  // Variables used for tracking and calculating in Round Robin
  int proc_left = num_proc;   // make a copy of the # of processes
  int elaps_time = 0;         // will be elapsed time (time that has passed)
  double total_wait = 0.0;    // used to keep track the total wait of all processes

  // loops until all processes are completed
  while(proc_left != 0)
  {
    // loops through the number of processes
    for(int p = 0 ; p < num_proc ; ++p)
    {
      // Checks if the time left is more than the TIME_QUANTUM
      if(track_time[p] > TIME_QUANTUM)
      {
        track_time[p] -= TIME_QUANTUM;  // the time associated with that processes is decreased by TIME_QUANTUM
        elaps_time += TIME_QUANTUM;     // add to the elapsed time
      }
      else if(track_time[p] > 0)    // checks time left on the process is more than 0. Based on last if statement this is TIME_QUANTUM > x > 0
      {
        elaps_time += track_time[p];  // add onto the elapsed time
        track_time[p] = 0;            // This process is completed so zero out time
        proc_left -= 1;               // Since this process is completed decrement the # of process left by 1

        total_wait += elaps_time - burst_time[p];   // elaps_time - burst_time[p] = wait time of this processes since arrival time = 0
        printf("P%d | Completion: %d unit(s) | Wait:  %d unit(s)\n", p+1, elaps_time, elaps_time-burst_time[p]);
      }
    }
  }
  printf("\nAverage waiting time: %f\n", total_wait/num_proc);
}

