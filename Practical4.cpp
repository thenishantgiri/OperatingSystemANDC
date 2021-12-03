#include<string.h>
#include<iostream>
using namespace std;

int main(int argc , char**argv)
{
    char str[100]="";

    strcat(str , "ls -l ");

    strcat(str ,argv[1]);
    
    strcat(str ,"| awk '{print $1 , $6 , $7 , $8 }'");

    system(str);

    return 0;
}
