//SJF scheduling algorithm

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Please enter the number of processes: ";
    cin>>n;

    int burst[n],process[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Please enter the CPU Burst Time for process P"<<i+1<<" :";
        cin>>burst[i];
        process[i]=i+1;
    }

    int j,k;
    int temp1,temp2;
    for(j=1; j<n; j++)                //sorting burst time and swapping elements of process[] along with burst[]
    {
        temp1=burst[j];
        temp2=process[j];
        for(k=j; k>0 && temp1<burst[k-1]; k--)
        {
            burst[k]=burst[k-1];
            process[k]=process[k-1];
        }

        burst[k]=temp1;
        process[k]=temp2;
    }


    int wait_time[n],turnaround_time[n];

    wait_time[0]=0;
    for(int i=1; i<n; i++)
        wait_time[i]=wait_time[i-1]+burst[i-1];     //calculating wait time

    for(int i=0; i<n; i++)
        turnaround_time[i]=wait_time[i]+burst[i];       //calculating turnaround time



    float avg_wt=0,avg_tt=0;

    cout<<"Processes \t  Burst Time \t   Waiting Time  \t  Turnaround Time"<<endl;       //printing wait time & turnaround time
    for(int i=0; i<n; i++)
    {
        cout<<"P"<<process[i]<<"  \t\t   "<<burst[i]<<"   \t\t      "<<wait_time[i]<<"   \t\t\t   "<<turnaround_time[i]<<endl;
        avg_wt+=wait_time[i];               //calculating total sum of wait time
        avg_tt+=turnaround_time[i];         //calculating total sum of turnaround time
    }

    avg_wt=avg_wt/n;                //calculating avg wait time
    avg_tt=avg_tt/n;                //calculating avg turnaround time

    cout<<"\nAverage Waiting Time = "<<avg_wt<<endl;
    cout<<"\nAverage Turnaround Time = "<<avg_tt<<endl;

    return 0;
}


