#include <iostream>		//input output stream
#include <unistd.h>		//it is used because fork() is defined in it
#include <sys/types.h>		//it is used for type pid_t for process ID

using namespace std;

int main()
{
    pid_t pid;			//creating process id using system id pid_t

    pid=fork();			//calling fork command

    cout<<"pid = "<<pid<<endl;	//printing process id, this statement will run for both child and process

    return 0;
}