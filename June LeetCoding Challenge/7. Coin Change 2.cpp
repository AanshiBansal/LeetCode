int change(int amount, vector<int>& coins) {
    vector<int>dp(amount+1,0);
    dp[0]=1;
    for(int val:coins){
        for(int i=val;i<=amount;i++){
            dp[i]+=dp[i-val];
        }
    }
    return dp[amount];
}
