#include <iostream>
using namespace std;

int counts1(int v,int k)
{
    int counts=0;
    int tmp;
    for(int i = 0 ;i<=v;i++)
    {
        tmp = i;
        while(tmp)
        {
            if(tmp%10 == k)
            {
                counts++;
                
            }
            tmp/=10;
        }
    }
    return counts;
}



int counts2(int v,int k)
{
    v=v>=0?v:-v;
    if(k>9)
    {
        return -1;
    }

    int ten=1;
    int counts=0;

    int cur,low,high;
    
    while(v/ten != 0)
    {
        cur = (v/ten)%10;
        low = v%ten;
        high = v/(ten*10);
        cout<<"v:ten:high:cur:low = "<<v<<" : "<<ten<<" : "<<high<<" : "<<cur<<" : "<<low<<endl;

        if(cur<k)
        {
            counts+=high*ten;
        }else if(cur == k){
            counts+=high*ten+low+1;
        }else if(cur > k){
            counts+=(high+1)*ten;
        }

        ten*=10;
    }

    return counts;
}

int main()
{
    int v=12221,k=3;
    // cin>>v>>k;
    cout<<"counts1: "<<counts1(v,k)<<endl;
    cout<<"counts2: "<<counts2(v,k)<<endl;
    
}