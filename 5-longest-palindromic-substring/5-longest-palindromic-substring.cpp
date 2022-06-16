class Solution {
private:
    int isPalindrome(string &s, int i, int j,vector<vector<int>>&dp){
        if(i>=j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]!=s[j])
            return dp[i][j]=0;
        return dp[i][j]=isPalindrome(s,i+1,j-1,dp);
    }
public:
    string longestPalindrome(string s) {
        string ans="";
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j,dp)==1){
                    if(j-i+1>ans.size())
                        ans=s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};