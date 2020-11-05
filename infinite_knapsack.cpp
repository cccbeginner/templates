struct stuff{int weight,value;}stuffs[101];
int dp[1001];

void infinite_knapsack(){
    int n,m;//number of stuffs, maximum weight
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> stuffs[i].weight >> stuffs[i].value;
    for(int i = 1; i <= n; i++){
        for(int j = stuffs[i].weight; j <= m; j++){
            int k = dp[j-stuffs[i].weight]+stuffs[i].value;
            if(k > dp[j])dp[j] = k;
        }
    }
    cout << dp[m] << endl;
}
