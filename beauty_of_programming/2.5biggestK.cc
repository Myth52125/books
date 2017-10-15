#include <iostream>
#include <vector>

using namespace std;

size_t findBigK_partition(vector<int> &source,size_t start,size_t end)
{

    size_t low=start;
    for(size_t i=start;i<end;i++)
    {
        if(source[i]<source[end])
        {
            swap(source[i],source[low]);
            low++;
        }
    }
    swap(source[low],source[end]);
    return low;
}
//
void findBigK_quicksort(vector<int> &source ,size_t start,size_t end,const size_t &k)
{
    if(start >= end)
    {
        return;
    }
    size_t mid = findBigK_partition(source,start,end);
    
    if(mid > k)
    {
        findBigK_quicksort(source,start,mid,k);
    }else if(mid == k){
        return ;
    }else if(mid >k){
        findBigK_quicksort(source,mid,end,k);
    }
}

int findBigK_quick(vector<int> source,size_t k)
{
    k=source.size()-k;
    findBigK_quicksort(source,0,source.size(),k);
    return source[k];
}
