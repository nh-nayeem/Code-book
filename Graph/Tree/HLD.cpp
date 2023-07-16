ll dis[N],vis[N],son[N],fa[N],head[N],cnt[N],sz[N],lvl[N],tmp[N];
vi adj[N];
ll tr[N*2];
ll dfs(ll nd,ll p)
{
    sz[nd]=1;
    ll mx=0;
    for(ll to:adj[nd]){
        if(to==p)continue;
        sz[nd]+=dfs(to,nd);
        if(mx<sz[to]){          
            mx=sz[to];
            son[nd]=to;     ///heavy edge
        }
    }
    return sz[nd];
}
ll t=0;
void hld(ll nd,ll p,ll h,ll d)
{
    fa[nd]=p,dis[nd]=++t,head[nd]=h,lvl[nd]=d;
    for(auto to:adj[nd]){
        if(to!=p&&son[nd]==to){     /// mark heavy nodes first
            hld(to,nd,h,d+1);
            break;
        }
    }
    for(auto to:adj[nd]){
        if(to!=p&&son[nd]!=to){     ///mark light edges
            hld(to,nd,to,d+1);        
        }
    }
}
int get_res(int u,int v,int n)      ///u,v are the original nodes.Not the dis[nd].n is used for segment_tree.
{
    int ans=0;
    while(1)
    {
        if(dis[u]>dis[v])swap(u,v);
        if(head[u]==head[v]){
            int f=query(1,1,n,dis[u],dis[v]);           ///u is also the lca
            ans=max(ans,f);
            return ans;
        }
        int l=head[v];
        int f=query(1,1,n,dis[l],dis[v]);
        ans=max(ans,f);
        v=fa[head[v]];
    }
    return ans;
}

int main()
{
    dfs(1,1);
    hld(1,-1,1,0);
    for(ll i=1;i<=n;i++)tmp[dis[i]]=ara[i];     ///use tmp[] array for building segment tree
    build(1,1,n);     ///segment tree
    ///update(1,1,n,dis[a],10);    ///update this way
}
