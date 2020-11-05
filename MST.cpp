struct edge{
    int i,j,c;
    bool operator<(const edge &rhs){
        return c < rhs.c;
    }
}edges[200000];

int n,m;
vector<int> parent;
vector<int> siz;

int find_parent(int k){//find k's parent
    if(parent[k] == k)return k;
    return parent[k] = find_parent(parent[k]);
}

bool Union(int u, int v){
    int U = find_parent(u);
    int V = find_parent(v);
    if(U == V)return false;
    if(siz[U] < siz[V])swap(U, V);
    siz[U] += siz[V];
    parent[V] = U;

    return true;
}

vector<edge> MST(int n, int m){//n nodes, m edges
    sort(edges, edges+m);
    parent.resize(n);
    siz.resize(n);
    for(int i = 0; i < n; ++i){
        parent[i] = i;
        siz[i] = 1;
    }
    
    vector<edge> ret;
    for(int i = 0; i < m; ++i){
        if(Union(edges[i].i, edges[i].j)){
            ret.push_back(edges[i]);
        }
    }
    return ret;
}
