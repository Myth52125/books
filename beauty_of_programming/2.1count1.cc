#include <iostream>
using namespace std;
int counts1(int v)
{
    int counts = 0;
    while(v)
    {
        if(v%2 == 1)
        {
            counts++;
        }
        v/=2;
    }
    return counts;
}

int counts2(int v)
{
    int counts = 0;
    while(v)
    {
        counts += v & 0x01;
        v>>=1;
    }
    return counts;
}
