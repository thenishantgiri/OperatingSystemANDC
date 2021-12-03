#include <iostream>
using namespace std;

int main()
{
    cout << "----------MEMORY Information----------\n";
    system("cat /proc/meminfo | grep 'MemTotal'");
    system("cat /proc/meminfo | grep 'MemFree'");
    system("cat /proc/meminfo | grep 'MemAvailable'");

    cout << "\n\n";
    system("vmstat -s | grep 'total memory'");
    system("vmstat -s | grep 'used memory'");
    system("vmstat -s | grep 'free memory'");

    return 0;
}
