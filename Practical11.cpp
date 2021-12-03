#include <iostream>

using namespace std;

void waiting_time(struct process a[], int n);

struct process
{
    int process_id;
    int burst_time;
    int waiting_time;
    int arrival_time;
    int remain_time;
} arr[100];

int process_finish[100];

int main()
{
    arr[99].remain_time = 9999;

    int n; //No of process in variable n

    cout << "\nPlease enter the number of Processes : ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) //Take the Burst time for each process by using loop
    {

        arr[i].process_id = i + 1; //increment the process_id by 1 after each burst_time

        cout << "Please enter the CPU Burst Time of P" << i + 1 << " : ";

        cin >> arr[i].burst_time;

        arr[i].remain_time = arr[i].burst_time; //copy each process burst_time to another array remain_time[]

        cout << "Please enter the Arrival Time : ";

        cin >> arr[i].arrival_time;
        cout << endl;
    }

    waiting_time(arr, n);
    return 0;
}

void waiting_time(struct process a[], int n)

{

    int remain = 0, sum_wait = 0, sum_turnaround = 0, endTime, smallest;

    cout << "\n\nProcess  Turnaround Time  Waiting Time\n\n";

    int process_f = 0; // handle the INDEX of array process_finish.

    for (int time = 0; remain != n; time++)
    {
        smallest = 99;

        for (int i = 0; i < n; i++)
        {
            if ((a[i].arrival_time <= time) && (a[i].remain_time < a[smallest].remain_time) && (a[i].remain_time > 0))
            {
                smallest = i;
            }
        }

        a[smallest].remain_time--;

        if (a[smallest].remain_time == 0)
        {
            process_finish[process_f] = smallest + 1; //to assign a process # which finish the total job
            process_f++;
            a[smallest].process_id = smallest + 1; //to ssign a process_id

            int tt;

            remain++; //One process complete the total job

            endTime = time + 1; //Total competional time of process

            tt = endTime - a[smallest].arrival_time; //Calculate the TURNaround TIME (competionalTime - TT )

            a[smallest].waiting_time = tt - a[smallest].burst_time; //Calculate the Waiting Time

            cout << "\nP[" << smallest + 1 << "]\t\t" << tt << "\t\t" << a[smallest].waiting_time;

            sum_wait += tt - a[smallest].burst_time; //For find Average Waiting Time
        }
    }

    cout << "\n\nAverage Waiting Time = " << sum_wait * 1.0 / n;
}
