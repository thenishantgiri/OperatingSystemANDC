//non-preemptive priority scheduling algorithm
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Process
{
    int pid;
    int bt;
    int priority;
};

bool comparison(Process a, Process b)
{
    return (a.priority > b.priority);
}

void findWaitingTime(Process proc[], int n, int wt[])
{
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = proc[i - 1].bt + wt[i - 1];
}

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);

    cout << "\nProcesses  "
         << " CPU Burst time  "
         << " Waiting time  "
         << " Turn around time\n";

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].pid << "\t\t" << proc[i].bt << "\t    " << wt[i] << "\t\t  " << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << (float)total_wt / (float)n;
    cout << "\nAverage Turn around Time = " << (float)total_tat / (float)n;
}

void priorityScheduling(Process proc[], int n)
{
    std::sort(proc, proc + n, comparison);

    cout << "\nOrder of execution: ";
    for (int i = 0; i < n; i++)
    {
        cout << proc[i].pid << " ";
    }
    cout<< endl;
    findavgTime(proc, n);
}

int main()
{
    int n;
    cout << "\nPriority Scheduling\nPlease enter the number of Processes = ";
    cin >> n;
    Process *proc = new Process[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nPlease enter the CPU Burst Time for Process P" << i + 1 << "= ";
        cin >> proc[i].bt;
        cout << "Please enter the Priority of Process P" << i + 1 << "= ";
        cin >> proc[i].priority;
        proc[i].pid = i + 1;
    }
    priorityScheduling(proc, n);
    return 0;
}
