#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please enter the number of processes: ";
    cin >> n;
    float total, wait[n];
    float p[n], twaiting = 0, waiting = 0;
    int proc;
    int stack[n];
    float brust[n], arrival[n], sbrust, temp[n], top = n, prority[n];
    int i;

    for (i = 0; i < n; i++)
    {
        p[i] = i;
        stack[i] = i;
        cout << "\nPlease enter the Arrival Time: ";
        cin >> arrival[i];
        cout << "Please enter the CPU Brust Time: ";
        cin >> brust[i];
        cout << "Please enter the Priority Time: ";
        cin >> prority[i];
        temp[i] = arrival[i];
        sbrust = brust[i] + sbrust;
    }

    for (i = 0; i < sbrust; i++)
    {
        //section 1
        proc = stack[0];
        if (temp[proc] == i)
            twaiting = 0;
        else
            twaiting = i - (temp[proc]);
        temp[proc] = i + 1;
        wait[proc] = wait[proc] + twaiting;
        waiting = waiting + (twaiting);
        brust[proc] = brust[proc] - 1;

        if (brust[proc] == 0)
        {
            for (int x = 0; x < top - 1; x++)
                stack[x] = stack[x + 1];
            top = top - 1;
        }

        for (int z = 0; z < top - 1; z++)
        {
            if ((prority[stack[0]] > prority[stack[z + 1]]) && (arrival[stack[z + 1]] <= i + 1))
            {
                int t = stack[0];
                stack[0] = stack[z + 1];
                stack[z + 1] = t;
            }
        }
    }

    cout << "\nAverage Waiting Time : " << waiting / n;
    float tu = (sbrust + waiting) / n;
    cout << endl
         << "Average Turnaround Time : " << tu << endl;
    return 0;
}
