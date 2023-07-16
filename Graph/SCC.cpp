vector<int>adj[N],adj_rev[N];
struct SSS{
    vector<vector<int>>adj_scc;
    vector<int>order,components,roots,vis;
    SSS(int n){
        adj_scc.resize(n+1);
        roots.resize(n+1);
        vis.resize(n+1);
    }
    void dfs(int nd)
    {
        vis[nd]=true;
        for(auto to:adj[nd])if(!vis[to])dfs(to);
        order.pb(nd);
    }
    void scc(int nd)
    {
        vis[nd]=true;
        components.pb(nd);
        for(auto to:adj_rev[nd])if(!vis[to])scc(to);
    }
    void condensation_graph(int n)
    {
        for(int i=1;i<=n;i++)
            for(auto to:adj[i])
                if(roots[i]!=roots[to])         ///add edge if part of two different cc.
                    adj_scc[roots[i]].pb(roots[to]);       
    }
    int solve(int n)
    {
        for(int i=0;i<=n;i++)vis[i]=0;
        for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
        reverse(order.begin(),order.end());
        for(int i=0;i<=n;i++)vis[i]=0;
      
        int total_scc = 0;
        for(auto x:order){
            if(!vis[x]){
                scc(x);
    //            for(auto y:components)roots[y] = components.back();           ///for condensation graph
                ///do stuffs here eg: total no of scc
                total_scc++;
                components.clear();
            }
        }
        return total_scc;
    }
};
