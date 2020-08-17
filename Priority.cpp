/*Muhammad Nur Firdaus Bin Muhamed Haireen (1815259)
Izzul Ismail Bin Ibrahim (1817963)
Mustaqim Bin Abdul Karim (1813739)
Muhammad Hassan Bin M Ashhuri (1812637)*/

#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

struct Process
{
	int ccode;
	int duration;
	int priority;
	int arrival_time;
};

bool comp(Process a,Process b) 
{ 
	if(a.arrival_time == b.arrival_time) 
	{ 
		return a.priority<b.priority; 
	} 
	else
	{ 
    	return a.arrival_time<b.arrival_time; 
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
  
		// If waiting time is negative, change it into zero 
      
    	if(waitingTime[i]<0) 
    	{ 
    		waitingTime[i]=0; 
    	} 
	}
	
}

void findTurnAroundtime(int turnaroundTime[], int waitingTime[], Process proc[], int n)
{
	for(int i=0;i<n;i++) 
	{ 
	    turnaroundTime[i]=proc[i].duration + waitingTime[i]; 
	} 
}

void priorityScheduling(Process proc[], int n)
{
	int waitingTime[n], turnaroundTime[n];
	double waitavg=0, turnavg=0;
	findWaitingTime(waitingTime, proc, n);
	findTurnAroundtime(turnaroundTime,waitingTime, proc, n);
	cout<<"Process_no\tTurn_Around_Time\tWaiting_Time"<<endl;
	  
	for(int i=0;i<n;i++) 
    { 
        waitavg += waitingTime[i]; 
        turnavg += turnaroundTime[i]; 
          
        cout<<proc[i].ccode<<"\t\t"<<turnaroundTime[i]<<"\t\t\t"<<waitingTime[i]<<endl; 
    } 
    cout<<"Average waiting time is : "; 
    cout<<waitavg/(float)n<<endl; 
    cout<<"average turnaround time : "; 
    cout<<turnavg/(float)n<<endl; 
}

int main()
{
	Process proc[] = {{2201, 3, 2, 1}, {3401, 2, 3, 2}, {1103, 1, 1, 3}};
	int n = sizeof proc / sizeof proc[0];
	sort(proc, proc+n, comp);
	priorityScheduling(proc, n);
	return 0;
}
