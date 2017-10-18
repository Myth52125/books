#include <iostream>
#include <cstring>
bool hasStr1(char *source,size_t len,char *target)
{
    char tmp=source[0];
    for(int i=0;i<len-1;i++)
    {
        source[i]=source[i+1];
    }
    source[len-1]=tmp;

    if(strstr(source,target))
    {
        return true;
    }
    return false;
}

using namespace std;
bool hasStr2(string source,string target)
{
    if(source.size()<target.size())
    {
        return false;
    }
    for(int i=0;i<source.size();i++)
    {
        if(strstr(source.c_str(),source.c_str()))
        {
            return true;
        }
        source.push_back(source[i]);
    }
    return false;
}