class Solution {
private:
    int util(int n, vector<int>&dp){
        if(n<=1)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=util(n-1,dp)+util(n-2,dp);
    }
public:
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return util(n,dp);
    }
};