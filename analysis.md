# Group Members
Muhammad Nur Firdaus Bin Muhamed Haireen (1815259)
Izzul Ismail Bin Ibrahim (1817963)
Mustaqim Bin Abdul Karim (1813739)
Muhammad Hassan Bin M Ashhuri (1812637)

# Introduction

The algorithm that we have chosen are First Come First Serve(FCFS) algorithm, Shortest-Job-First(SJF) algorithm and Priority Scheduling. We chose all these algorithms because the algorithms is non-preemptive scheduling algorithm. Once the CPU is allocated to a process, the process holds the CPU until it gets terminated or it reaches a waiting state. 

# Input
course 2201 : duration = 3, priority = 2, arrival time = 3
course 3401 : duration = 2, priority = 3, arrival time = 2
course 1103 : duration = 1, priority = 1, arrival time = 3


# Consideration

We have considered that in class scheduling, when a class is started, there is no way that other classes could interfere the running class. The other class should wait until the running class to over so that the class could be in run. The running class should not be stopped to make other class to run.   


# Analysis

## FCFS

The First Come First Serve (FCFS) algorithm works where the process which arrives first, gets executed first. It is the same as the FIFO(First In First Out) queue in data structure where the data that is added first is the one who will leave first. We use the FCFS algorithm because in class scheduling, the course already be set by the Kulliyyah and the department. So as the course already be decided, some lecturers that are meant to teach in the morning should be in the class in the morning, and other lecturers could not interfere the class to teach his or her subject in the respective time.


## Priority Scheduling

The process can be prioritized based on memory and time requirements. In this situation, we can assume that the lecturer will prioritize the most priority courses which not have a lecturer to teach rather than the courses that already have a lecturer. In the integer form, the priority ranging from 0 - 10 where 0 represents the lowest priority, and 10 represents the higher priority. 
Average waiting time = 1.66667
Average turn around time = 3.66667


## SJF

The Shortest job first (SJF) is a scheduling policy which the waiting process with the smallest execution time to execute next. This makes this algorithm can reduce the average waiting time for the next process. This SJF is also a non-preemptive algorithm like FCFS CPU scheduling. SJF has the benefit on having the most minimum average waiting time among other scheduling algorithms.
Average waiting time = 1.33333 seconds
Average turn around time = 3.33333 seconds


