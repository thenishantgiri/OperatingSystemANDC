//FCFS scheduling algorithm
#include<iostream>
using namespace std;

int main()
{
    int n;

    cout<<"Please enter the number of processes: ";
    cin>>n;

    int burst_time[n];
    for(int i=1; i<=n; i++)
    {
        cout<<"Please enter the Burst time for P"<<i<<": ";
        cin>>burst_time[i];
    }

    int wt_time[n];

    wt_time[1]=0;
    for(int i=2; i<=n; i++)                 //calculating waiting time for each process
    {
        wt_time[i]=wt_time[i-1]+burst_time[i-1];
    }

    int turnaround_time[n];
    for(int i=1; i<=n; i++)                 //calculating turnarond time for each process
    {
        turnaround_time[i]=wt_time[i]+burst_time[i];
    }

    float avg_wait_time=0, avg_turnaround_time=0;

    for(int i=1;i<=n;i++)
    {
        avg_wait_time+= wt_time[i];               //calculating sum of waiting time of all process
        avg_turnaround_time+= turnaround_time[i];       //calculating sum of trunaround time of all process
    }

    cout<<"     Burst Time \tWaiting Time \tTurnaround Time"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<"P"<<i+1<<"  \t"<<burst_time[i]<<"\t\t"<<wt_time[i]<<"\t\t"<<turnaround_time[i]<<endl;
    }


    avg_wait_time= avg_wait_time/n;
    avg_turnaround_time= avg_turnaround_time/n;

    cout<<"\nAverage Waiting time = "<<avg_wait_time<<endl;
    cout<<"\nAverage Turnaround time = "<<avg_turnaround_time<<endl;
    return 0;
}

