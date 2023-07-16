int lg[N];
int tab[N][35];
void build(int n)
{
    lg[1]=0;
    for(int i=2;i<N;i++)
        lg[i]=lg[(i>>1)]+1;

    for(int k=1;k<=23;k++){		
        for(int i=1;i+(1<<k)-1<=n;i++)		/// for min/max i + (1<<k) may become > n
            tab[i][k] = min(tab[i][k-1],tab[i+(1<<(k-1))][k-1]); 
}
int query(int l,int r)
{
    int d = lg[r-l+1];
    return min(tab[l][d],tab[r-(1<<d)+1][d]);	/// i + (1<<d) covers range [i,i+(1<<d)-1]
}
