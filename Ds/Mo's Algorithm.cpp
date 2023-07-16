const int bsize = 450;
struct mo{
    int l,r,idx;
    mo(){}
    mo(int l_,int r_,int idx_){l=l_,r=r_,idx=idx_;}
};
vector<mo>qr;
bool cmp(mo p,mo q)
{
    int x = p.l/bsize;
    int y = q.l/bsize;
    if(x != y) return x<y;
    return (x&1)?(p.r < q.r):(p.r > q.r);
}
void MO()
{
    int L=1,R=0;
    for(auto x:qr)
    {
        int l = x.l,r = x.r;
        while(R<r)add(++R);
        while(L<l)del(L++);
        while(L>l)add(--L);
        while(R>r)del(R--);

    }
}
