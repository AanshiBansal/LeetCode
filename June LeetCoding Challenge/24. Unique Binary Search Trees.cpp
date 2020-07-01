//Bottom up DP
int numTrees(int n) {
    vector<int>dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int trees=0;
        for(int j=1;j<=i;j++)
            trees+=dp[j-1]*dp[i-j];
        dp[i]=trees;
    }
    return dp[n];       
}
