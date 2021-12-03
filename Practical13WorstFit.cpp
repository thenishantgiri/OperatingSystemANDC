/* program to implement worst-fit allocation strategies */

#include <iostream>  //input output stream
using namespace std; // standard namespace

int main()
{ // main function
    int NumberOfBlock, NumberOfProcess, MemoryBlock[20], Processes[20];

    cout << " Please enter the number of Memory Blocks: ";
    cin >> NumberOfBlock; // enter number of blocks

    cout << " Please enter the number of processes: ";
    cin >> NumberOfProcess; // enter number of processes

    cout << " Please enter the size of " << NumberOfBlock << " blocks: ";
    for (int i = 0; i < NumberOfBlock; i++)
    {
        cin >> MemoryBlock[i];
    } // enter size of each mem block

    cout << " Please enter the size of " << NumberOfProcess << " processes: ";
    for (int i = 0; i < NumberOfProcess; i++)
    {
        cin >> Processes[i];
    } // enter size of each processes

    // performing worst fit allocation strategies
    for (int i = 0; i < NumberOfProcess; i++)
    {
        /* comparing each process with each memory block */
        int max = MemoryBlock[0];
        int pos = 0;
        for (int j = 0; j < NumberOfBlock; j++)
            if (max < MemoryBlock[j])
            {
                max = MemoryBlock[j];
                pos = j;
            }
        /* displaying details */
        if (max >= Processes[i])
        {
            cout << "\nProcess " << i + 1 << " is allocated to block "
                 << pos + 1;
            MemoryBlock[pos] = MemoryBlock[pos] - Processes[i];
        }
        else
        {
            cout << "\nProcess " << i + 1 << " can't be allocated!";
        }
    }
    cout << endl;
    return 0;
}