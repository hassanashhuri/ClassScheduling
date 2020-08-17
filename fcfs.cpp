/*Muhammad Nur Firdaus Bin Muhamed Haireen (1815259)
Izzul Ismail Bin Ibrahim (1817963)
Mustaqim Bin Abdul Karim (1813739)
Muhammad Hassan Bin M Ashhuri (1812637)*/

#include <iostream>
using namespace std;

struct Process
{
	int ccode;
	int duration;
	int priority;
	int arrival_time;
};

void sorting(Process proc[], int n)
{
	Process a;
	for (int i = 0; i < n; ++i) 
    {   
	
		for (int j = i + 1; j < n; ++j)
        {
		    if (proc[i].arrival_time > proc[j].arrival_time) 
            {
				a =  proc[i];
                proc[i] = proc[j];
                proc[j] = a;
            }
        }
	}
}

void findWaitingTime(int waitingTime[], Process proc[], int n)
{
	int run[n];
	run[0] = proc[0].arrival_time; 
	waitingTime[0]=0; 
  
  
	for(int i=1;i<n;i++) 
	{ 
		run[i]=proc[i-1].duration + run[i-1]; 
  
		waitingTime[i]=run[i]-proc[i].arrival_time; 
      
    	if(waitingTime[i]<0) 
    	{ 
    		waitingTime[i]=0; 
    	} 
	}
}

void findTurnAroundTime(int turnaroundTime[], int waitingTime[], Process proc[], int n)
{
	for (int i = 0; i < n ; i++)
    {
        turnaroundTime[i] = proc[i].duration + waitingTime[i];
    }
}

fcfsScheduling(Process proc[], int n)
{
	int waitingTime[n], turnaroundTime[n];
	int totalwait = 0, totalturn = 0;
	findWaitingTime(waitingTime, proc, n);
	findTurnAroundTime(turnaroundTime,waitingTime, proc, n);
	
	cout << "Processes  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";
    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        totalwait = totalwait + waitingTime[i];
        totalturn = totalturn + turnaroundTime[i];
        cout << "   " << proc[i].ccode << "\t\t" << proc[i].duration <<"\t    "<< waitingTime[i] <<"\t\t  " << turnaroundTime[i] <<endl;
    }
 
    cout << "Average waiting time = "<< (float)totalwait / (float)n;
    cout << "\nAverage turn around time = "<< (float)totalturn / (float)n;
}

int main()
{
	Process proc[] = {{2201, 3, 2, 1}, {3401, 2, 3, 2}, {1103, 1, 1, 3}};
	int n = sizeof proc / sizeof proc[0];
	sorting(proc, n);
	fcfsScheduling(proc, n);


	return 0;
}
