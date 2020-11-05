const int MAXN = 100;
int lcs[MAXN+1][MAXN+1];
int LCS(string s1, string s2){
    for(int i = 1; i <= s1.size(); ++i){
        for(int j = 1; j <= s2.size(); ++j){
            if(s1[i-1] == s2[j-1]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }else{
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
    }
    return lcs[s1.size()][s2.size()];
}
