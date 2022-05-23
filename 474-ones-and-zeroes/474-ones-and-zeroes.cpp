class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(string s:strs){
            int ones=0;
            int zeros=0;
            for(char c:s){
                if(c=='1')
                    ones++;
                else
                    zeros++;
            }
            for(int i=m;i>=0;i--){
                for(int j=n;j>=0;j--){
                    if(i-zeros>=0 && j-ones>=0)
                        dp[i][j]=max(dp[i][j],dp[i-zeros][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};