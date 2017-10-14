#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
using namespace std;

int findTarget(vector<int> source)
{
    int target ;
    int counts=0;
    for(int i = 0;i<source.size();i++)
    {
        if(counts ==0)
        {
            target = source[i];
        }else{
            if(target  == source[i])
            {
                counts++;
            }else{
                counts--;
            }
        }
    }
    return counts;
}

int findTarget3(vector<int> source)
{
    map<int,int> memo;
    for(int i:source)
    {
        memo[i]++;
    }

    for(map<int,int>::iterator it = memo.begin();it != memo.end();it++)
    {
        if(it->second >source.size()/2)
        {
            return it->first;
        }
    }
    return -1;  
}
int main()
{
    vector<int> source{2,2,2,2,2,2,2,2,2,2,1,1,1,1};
    cout<<findTarget3(source)<<endl;

}