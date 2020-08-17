#include <iostream>
using namespace std;

struct Process
{
	int ccode;
	int duration;
	int priority;
	int arrival_time;
};

void findWaitingTime(int waitingTime[], Process proc[], int n)
{
	int remainTime[n];
   	for (int i = 0; i < n; i++)
   	{
   		remainTime[i] = proc[i].duration;
   	}
   	int complete = 0, t = 0, minm = INT_MAX;
   	int shortest = 0, finish_time;
   	bool check = false;
   	while (complete != n) {
    	for (int j = 0; j < n; j++) 
		{
        	if ((proc[j].arrival_time <= t) && (remainTime[j] < minm) && remainTime[j] > 0) 
			{
            	minm = remainTime[j];
            	shortest = j;
            	check = true;
         	}
      	}
      	if (check == false) 
		{
        	t++;
         	continue;
      	}
      // decrementing the remaining time
      	remainTime[shortest]--;
      	minm = remainTime[shortest];
      	if (minm == 0)
		{
        	minm = INT_MAX;
         	// If a process gets completely
        } 	// executed
        if (remainTime[shortest] == 0) 
		{
            complete++;
            check = false;
            finish_time = t + 1;
            // Calculate waiting time
            waitingTime[shortest] = finish_time - proc[shortest].duration - proc[shortest].arrival_time;
            if (waitingTime[shortest] < 0)
               waitingTime[shortest] = 0;
        }
         // Increment time
        t++;
   }
}

void findTurnAroundTime(int turnaroundTime[], int waitingTime[], Process proc[], int n)
{
	for (int i = 0; i < n ; i++)
    {
        turnaroundTime[i] = proc[i].duration + waitingTime[i];
    }
}

sjfScheduling(Process proc[], int n)
{
	int waitingTime[n], turnaroundTime[n];
	int totalwait = 0, totalturn = 0;
	findWaitingTime(waitingTime, proc, n);
	findTurnAroundTime(turnaroundTime,waitingTime, proc, n);
	
	cout << "Processes  "<< " Burst time  "<< " Waiting time  " << " Turn around time" << " Time Arrival"<<endl;
    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        totalwait = totalwait + waitingTime[i];
        totalturn = totalturn + turnaroundTime[i];
        cout << "   " << proc[i].ccode << "\t\t" << proc[i].duration <<"\t    "<< waitingTime[i] <<"\t\t  " << turnaroundTime[i] << "\t\t   " << proc[i].arrival_time <<endl;
    }
 
    cout << "Average waiting time = "<< (float)totalwait / (float)n;
    cout << "\nAverage turn around time = "<< (float)totalturn / (float)n;
}

int main()
{
	Process proc[] = {{2201, 3, 2, 1}, {3401, 2, 3, 2}, {1103, 1, 1, 3}};
	int n = sizeof proc / sizeof proc[0];
	sjfScheduling(proc, n);


	return 0;
}
