#include<iostream>
using namespace std;

int main()
{
    cout<<"\n----------CPU Information----------\n";
    system("cat /proc/cpuinfo | grep 'cpu family'");
    system("cat /proc/cpuinfo | grep 'model'");
    system("cat /proc/cpuinfo | grep 'vendor'");

    cout<<"\n----------KERNEL Information----------\n";
    system("cat /proc/sys/kernel/osrelease");


    return 0;
}
