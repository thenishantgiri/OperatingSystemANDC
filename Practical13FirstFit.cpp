/* program to implement first-fit allocation strategies */

#include <iostream>
using namespace std;

int main()
{ // main function starts
    int MemoryBlock[10], Process[10], NumberOfBlock, NumberOfProcess, flags[10],
        allocation[10], i, j;

    for (i = 0; i < 10; i++)
    { // updating initial allocation status
        flags[i] = 0;
        allocation[i] = -1;
    }

    cout << "Please enter the number of Memory Blocks: ";
    cin >> NumberOfBlock; // enter number of memory block

    cout << "\nPlease enter the Size of each Memory Block: ";
    for (i = 0; i < NumberOfBlock; i++)
    {
        cin >> MemoryBlock[i];
    } // enter size of each memory block

    cout << "\nPlease enter the number of Processes: ";
    cin >> NumberOfProcess; // enter number of processes

    cout << "\nPlease enter each Process size: ";
    for (i = 0; i < NumberOfProcess; i++)
    {
        cin >> Process[i];
    } // enter size of each process

    /* allocating according to first fit strategies */
    for (i = 0; i < NumberOfProcess;
         i++)
    { // comparing each process to each memory block
        for (j = 0; j < NumberOfBlock; j++)
        {
            if (flags[j] == 0 && MemoryBlock[j] >= Process[i])
            {
                /* if the mem block is not allocated and size of process is less
                than mem block it will be allocated */

                allocation[j] = i; /* updating status of memory block to
                                      allocated and storing process number */
                flags[j] = 1;
                break;
            }
        }
    }
    /* displaying gannt chart table */
    cout << "\nBlock no.\tSize\t\tProcess number.\t\t Process Size";
    for (i = 0; i < NumberOfBlock; i++)
    {
        cout << "\n"
             << i + 1 << "\t\t" << MemoryBlock[i] << "\t\t";
        if (flags[i] == 1)
        {
            cout << allocation[i] + 1 << "\t\t\t" << Process[allocation[i]];
        }
        else
        {
            cout << "Not allocated";
        }
    }
    return 0;
}