#include <iostream>
#include <unistd.h>
#include<windows.h>

using namespace std;

void methodOne()
{
    int c=0;
    cout<<"start !"<<endl;
    while(true)
    {
        c++;
        // for(int i=0;i<9600000;i++)
        // {
        // }
        // sleep(10);
    }
    cout<<"endl !"<<endl;
}




int main()
{
    methodOne();
}

// #include<iostream>
// #include<Windows.h>
// #include<cmath>

// using namespace std;

// int eachTime = 100;
// void CPU(int busy,int idle);

// int main()
// {    
//     int level;    
//     cin >> level;    
//     int busyTime = eachTime*level / 100;    
//     int idleTime = eachTime - busyTime;    
//     CPU(busyTime,idleTime);    
//     return 0;
// }
// void CPU(int busy, int idle)
// {    
//     INT64 startTime = 0;    
//     while (true)
//     {        
//         startTime = GetTickCount();
//         while ((GetTickCount()-startTime)<=busy)        
//         {            
//             ;        
//         }        
//         Sleep(idle);    
//     }
// }