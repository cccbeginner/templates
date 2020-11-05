struct stuff{int weight, volume, value;}stuffs[101];
int dp[1001][1001];

void bi_loaded_knapsack(){
    int n,m1,m2;//number of stuffs, maximum weight, maximum volumn
    cin >> m1 >> m2 >> n;
    for(int i = 1; i <= n; i++)cin >> stuffs[i].weight >> stuffs[i].volume >> stuffs[i].value;
    for(int i = 1; i <= n; i++){
        for(int j = m1; j >= stuffs[i].weight; j--){
            for(int k = m2; k >= stuffs[i].volume; --k){
                dp[j][k] = max(dp[j][k], dp[j-stuffs[i].weight][k-stuffs[i].volume] + stuffs[i].value);
            }
        }
    }
    cout << dp[m1][m2] << endl;
}
