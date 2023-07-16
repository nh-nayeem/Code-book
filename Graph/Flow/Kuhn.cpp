vector<int>graph[MX];
bool vis[MX];
int match[MX];
bool dfs(int node){
	if(vis[node])return 0;
	vis[node] = 1;
	for(auto nx:graph[node]){
		if(match[nx]==-1 || dfs(match[nx])){
			match[node] = nx;
			match[nx] = node;
			return 1;
		}
	}
	return 0;
}
// inside main()
memset(match, -1, sizeof match);
while(1){
	memset(vis, 0, sizeof vis);
	bool cont = 0;
	for(int i=1;i<=n;i++){
		if(match[i]==-1)cont|=dfs(i);
	}
	if(cont==0)break;
}
int MCBM = 0;
for(int i=1;i<=n;i++){
	if(match[i]!=-1)MCBM++;
}
