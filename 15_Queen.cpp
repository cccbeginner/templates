int n;
int maze[20];
int ans;

void dfs(int depth, int col, int rsh, int lsh){//depth := row
    if(depth == n)++ans;
    else{
        int avail = ((1<<n) - 1) & ~col & ~rsh & ~lsh & maze[depth];
        while(avail){
            int lowbit = avail & -avail;
            avail ^= lowbit;
            dfs(depth+1, col | lowbit, (rsh | lowbit) >> 1, (lsh | lowbit) << 1);
        }
    }
}

int solve(int n){//calculate N queen
    ans = 0;
    for(int i = 0; i < n; ++i){
        maze[i] = (1<<n)-1;
    }
    dfs(0,0,0,0);
    return ans;
}
