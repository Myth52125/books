#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int min(int a,int b,int c)
{
    if(a<b)
    {
        b=a;
    }
    if(b>c)
    {
        b=c;
    }
    return b;
}

// string stra("qwert12");
// string strb("qwert");

int comparestr1_ass(vector<vector<int>> &memo,string &stra,size_t starta,string &strb,size_t startb)
{
    cout<<"compare: "<<starta<<" "<<startb<<endl;
    
    int a=INT32_MAX;
    int c=INT32_MAX;
    int b=INT32_MAX;
    if(starta > stra.size())
    {
        if(startb > strb.size())
        {
            memo[starta+1][startb+1]=0;
            return 0;
        } 
        memo[starta][startb]=abs(static_cast<int>(stra.size()-strb.size()));
        return memo[starta][startb];
    }
    if(startb > strb.size())
    {
        if(starta > stra.size())
        {
            memo[starta+1][startb+1]=0;
            return 0;
        } 
        memo[starta][startb]=abs(static_cast<int>(stra.size()-strb.size()));
        return memo[starta][startb];
    }

    //相等的情况
    if(stra[starta] == strb[startb])
    {
        cout<<"equal: "<<starta<<" "<<startb<<endl;
        if(memo[starta+1][startb+1] != 0)
        {
            return memo[starta+1][startb+1];
        }else{
            return comparestr1_ass(memo,stra,starta+1,strb,startb+1);
        }
    }

    //处理不相等的情况
    cout<<"__unequal xiugai: "<<starta<<" "<<startb<<endl;
    
    if(memo[starta+1][startb+1] != 0)
    {
        a=memo[starta+1][startb+1];
    }else{
        a=comparestr1_ass(memo,stra,starta+1,strb,startb+1);
    }
    cout<<"__unequal zengjia: "<<starta<<" "<<startb<<endl;
    
    if(memo[starta+1][startb] != 0)
    {
        b=memo[starta+1][startb];
    }else{
        b=comparestr1_ass(memo,stra,starta+1,strb,startb);
    }

    cout<<"__unequal shanchu: "<<starta<<" "<<startb<<endl;
    
    if(memo[starta][startb+1] != 0)
    {
        c=memo[starta][startb+1];
    }else{
    
        c=comparestr1_ass(memo,stra,starta,strb,startb+1);
    }

    int tmp;
    tmp = min(a,b,c);

    for(auto j:memo)
    {
        cout<<endl;
        for(auto i:j)
        {
            cout<<i<<"  ";
        }
    }
    cout<<endl;
    cout<<endl;

    return tmp;
}

int comparestr1(string stra,string strb)
{
    vector<vector<int>> memo(stra.size()+1,vector<int>(strb.size()+1,0));
    for(int i=0;i<=stra.size();i++)
    {
        memo[i][0]=i;
    }
    for(int i=0;i<=stra.size();i++)
    {
        memo[0][i]=i;
    }

    comparestr1_ass(memo,stra,0,strb,0);
    
    for(auto j:memo)
    {
        cout<<endl;
        for(auto i:j)
        {
            cout<<i<<"  ";
        }
    }
    cout<<endl;
    cout<<endl;
    return 1;    
}

int main()
{
    string stra("qwert12");
    string strb("qwert");
    comparestr1(stra,strb);
}
