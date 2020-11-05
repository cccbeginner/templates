const int MAXN = 200000;
int parent[MAXN+5];
int siz[MAXN+5];

void init(){
    for(int i = 0; i <= MAXN; ++i){
        parent[i] = i;
        siz[i] = 1;
    }
}

int find_parent(int k){//find k's parent
    if(parent[k] == k)return k;
    return parent[k] = find_parent(parent[k]);
}

void Union(int u, int v){
    int U = find_parent(u);
    int V = find_parent(v);
    if(U == V)return;
    if(siz[U] < siz[V])swap(U, V);
    siz[U] += siz[V];
    parent[V] = U;
}

//sample use: return true if u,v are in the same set
bool Query(int u, int v){
    int U = find_parent(u);
    int V = find_parent(v);
    return U == V;
}
