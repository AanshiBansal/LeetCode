class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int c:coins){
            if(c<=amount)
                dp[c]=1;
        }
        if(dp[amount]==1)
            return 1;
        for(int i=1;i<=amount;i++){
            if(dp[i]==INT_MAX){
                for(int c:coins){
                    if(i-c>=0 && dp[i-c]!=INT_MAX)
                        dp[i]=min(dp[i],dp[i-c]+1);
                }
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
};