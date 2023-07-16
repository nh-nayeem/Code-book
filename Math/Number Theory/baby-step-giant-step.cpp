const int md=100000007;
int bigpow(int a,int b)
{
    if(b==0) return 1;
    int x=bigpow(a,b>>1);
    x=(1LL*x*x)%md;
    if(b&1) x=(1LL*x*a)%md;
    return x;
}
int baby_step_giant_step(int a,int b)
{
    int m=ceil(sqrt(md));
    map<int,int> mp;
    int x=1;
    for(int i=0;i<m;i++)
    {
        mp[x]=i;
        x=(1LL*x*a)%md;
    }
    x=bigpow(x,md-2);
    int y=b;
    for(int i=0;i<m;i++)
    {
        if(mp.find(y)!=mp.end())
        {
            return i*m+mp[y];
        }
        y=(1LL*y*x)%md;
    }
    // assert(false);
    return -1;
}
