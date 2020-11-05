const int MAXV = 500000;
vector<int> edges[MAXV];
vector<int> weight[MAXV];
bool vis[MAXV];
struct state{
    int length, u;
    bool operator>(const state &rhs)const{
        return length > rhs.length;
    }
};

int dijkstra(int from, int to){//return shortest path length
    memset(vis, 0, sizeof(vis));
    priority_queue<state, vector<state>, greater<state> > pq;
    state ori = {.length = 0, .u = from};
    pq.push(ori);
    while(!pq.empty()){
        state tmd = pq.top();
        pq.pop();
        if(tmd.u == to)return tmd.length;
        if(vis[tmd.u])continue;
        vis[tmd.u] = 1;
        for(int i = 0; i < edges[tmd.u].size(); ++i){
            if(vis[edges[tmd.u][i]])continue;
            state nxt = {.length = tmd.length + weight[tmd.u][i], .u = edges[tmd.u][i]};
            pq.push(nxt);
        }
    }
    return -1;//there's no path between two nodes
}
