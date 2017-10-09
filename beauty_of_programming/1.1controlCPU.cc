#include <iostream>
#include <unistd.h>
// #include <windows.h>
#include <pthread.h>

using namespace std;

void *methodOne(void *)
{
    cout << "start !" << endl;
    while (true)
    {
    }
    cout << "endl !" << endl;
}

int main()
{
    pthread_t pid[4];
    for (int i = 0; i < 2; i++)
    {
        pthread_create(&pid[i], NULL, methodOne, NULL);
    }
    sleep(100);
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