vector<int> edges[100001];
int lca[100001][20];
int depth[100001];

void dfs(int u, int pre, int d){
    depth[u] = d;
    lca[u][0] = pre;
    for(int i = 1; i < 20; ++i){
        if(lca[u][i-1] == -1)break;
        lca[u][i] = lca[lca[u][i-1]][i-1];
    }
    for(int i = 0; i < SZ(edges[u]); ++i){
        if(edges[u][i] == pre)continue;
        dfs(edges[u][i], u, d+1);
    }
}

void build(){
    memset(lca, -1, sizeof(lca));
    dfs(0, -1, 0);
}

int LCA(int u, int v){
    if(depth[u] < depth[v])swap(u, v);
    int cut = depth[u]-depth[v];
    int idx = 0;
    while(cut){
        if(cut & (1<<idx)){
            cut -= (1<<idx);
            u = lca[u][idx];
        }
        ++idx;
    }
    if(u == v)return u;
    for(int i = 19; i >= 0; --i){
        if(lca[u][i] != lca[v][i]){
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    return lca[u][0];
}
