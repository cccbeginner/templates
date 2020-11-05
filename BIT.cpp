const int MAXN;
int BIT[MAXN+5];

void add(int k, int val){
    while(k <= MAXN){
        BIT[k] += val;
        k += (k&-k);
    }
}

int sum(int k){
    int ret = 0;
    while(k){
        ret += BIT[k];
        k -= (k&-k);
    }
    return ret;
}
