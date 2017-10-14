

int counts1(int v)
{
    int counts = 0;
    for(int i = 1;i<=v;i++)
    {
        int j = i;
        while(j%5 == 0)
        {
            counts++;
            j/=5;
        }
    }
    return counts;
}

int counts2(int v)
{
    int counts=0;
    while(v)
    {
        counts+=v/5;
        v/=5;
    }
    return counts;
}

int counts3(int v)
{
    int counts =0;
    while(v)
    {
        //这里其实就是相当于v/2
        v>>=1;
        counts+=v;
    }
}