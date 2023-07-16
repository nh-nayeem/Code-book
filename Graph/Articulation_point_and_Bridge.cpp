//1) u is root of DFS tree and it has at least two children. 
//2)the vertex v in the DFS tree is an articulation point if and only if  for any child to , low[to] >= dis[v]
vi adj[N];
vpi bridges;
int t=0;
int dis[N],low[N];
void dfs(int nd,int p)
{
    dis[nd]=++t;
    low[nd]=t;
    int childs=0;
    for(int to:adj[nd]){
        if(to==p)continue;
        if(dis[to]==0){
            dfs(to,nd);
            childs++;
            low[nd]=min(low[nd],low[to]);
            if(low[to]>dis[nd])                         /// >= for articulation_point
                bridges.pb(MP(min(to,nd),max(to,nd)));      ///or other functions.
        }
        else{
            low[nd]=min(low[nd],dis[to]);
        }
    }
    /// if(p==-1 && childs>0){}    ///only for articulation_point
}
