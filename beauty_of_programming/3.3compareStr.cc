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
            //  1234567
// string stra("qwert12");
// string strb("1qwert");

int comparestr1_ass(vector<vector<int>> &memo,string &stra,size_t starta,string &strb,size_t startb)
{

    cout<<"compare: "<<starta<<" "<<startb<<endl;
    
    int a=INT32_MAX;
    int c=INT32_MAX;
    int b=INT32_MAX;
    
 

    if(starta >= stra.size())
    {
        cout<<"___stra end"<<endl;
        if(startb >= strb.size())
        {
            return 0;
        } 
        memo[starta][startb]=strb.size()-startb;
        return memo[starta][startb];
    }
    if(startb >= strb.size())
    {
        cout<<"___strb end"<<endl;
        
        if(starta >= stra.size())
        {
            return 0;
        } 
        memo[starta][startb]=stra.size()-starta;
        return memo[starta][startb];
    }

    //相等的情况
    if(stra[starta] == strb[startb])
    {
        // cout<<"equal: "<<starta<<" "<<startb<<endl;
        if(memo[starta+1][startb+1] != 0)
        {
            memo[starta][startb]=memo[starta+1][startb+1];
            return memo[starta+1][startb+1];
        }else{
            memo[starta][startb]=comparestr1_ass(memo,stra,starta+1,strb,startb+1);
            return memo[starta+1][startb+1];
        }
    }

    //处理不相等的情况
    
    if(starta<stra.size() && startb<strb.size())
    {
    // cout<<"__unequal xiugai: "<<starta<<" "<<startb<<endl;
        if(memo[starta+1][startb+1] != 0)
        {
            a=memo[starta+1][startb+1];
        }else{
            a=comparestr1_ass(memo,stra,starta+1,strb,startb+1);
        }
    }
   
    
    if(starta<stra.size())
    {
    // cout<<"__unequal zengjia: "<<starta<<" "<<startb<<endl;
    
        if(memo[starta+1][startb] != 0)
        {
            b=memo[starta+1][startb];
        }else{
            b=comparestr1_ass(memo,stra,starta+1,strb,startb);
        }
    }
 

    
    if(startb<strb.size())
    {

        // cout<<"__unequal shanchu: "<<starta<<" "<<startb<<endl;
    
        if(memo[starta][startb+1] != 0)
        {
            c=memo[starta][startb+1];
        }else{
        
            c=comparestr1_ass(memo,stra,starta,strb,startb+1);
        }
    }
 
    
    int tmp;
    tmp = min(a,b,c);
    memo[starta][startb]=tmp+1;
    // cout<<"xiugai: "<<a<<" qita: "<<b<<" "<<c<<endl;
    // cout<<endl<<"end of: "<<starta<<" "<<startb<<" value: "<<tmp+1<<endl;
    

    
    // for(auto j:memo)
    // {
    //     cout<<endl;
    //     for(auto i:j)
    //     {
    //         cout<<i<<"  ";
    //     }
    // }
    // cout<<endl;
    // cout<<endl;
    // int tmp1;
    // cin>>tmp1;

    return tmp+1;
}

int comparestr1(string stra,string strb)
{
    vector<vector<int>> memo(stra.size()+2,vector<int>(strb.size()+2,0));
    // for(int i=0;i<=stra.size();i++)
    // {
    //     memo[i][0]=i;
    // }
    // for(int i=0;i<=strb.size();i++)
    // {
    //     memo[0][i]=i;
    // }

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


int compareStr2(string stra,string strb)
{
    vector<vector<int> > memo(stra.size()+1,vector<int>(strb.size()+1,0));

      for(int i=0;i<=stra.size();i++)
    {
        memo[i][0]=i;
    }
    for(int i=0;i<=strb.size();i++)
    {
        memo[0][i]=i;
    }
    for(int i=1;i<stra.size();i++)
    {
        for(int j=1;j<stra.size();j++)
        {
            if(stra[i-1]==strb[j-1])
            {
                memo[i][j]=memo[i-1][j-1];
            }else{
                memo[i][j]=min(memo[i-1][j],memo[i][j-1],memo[i-1][i-1])+1;
            }
        }
    }

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
}

int main()
{           //   01234567
    string stra("qwert12");
    string strb("1qwert");
    comparestr1(stra,strb);
    compareStr2(stra,strb);
}
