// DB-Memorization
/*
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
*/

// DB-Tabulation
/*
class Solution {
public:
    string longestPalindrome(string s) {
        string ans=s.substr(0,1);
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++)
                dp[i][j]=true;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }else{
                    dp[i][j]=false;
                }
                if(dp[i][j]){
                    if(j-i+1>ans.size())
                        ans=s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int n=s.size();
        for(int index=0;index<n;index++){
            int i=index;
            int j=index;
            while(i>=0 && j<n && s[i]==s[j]){
                i--;
                j++;
            }
            if(j-i-1>ans.size())
                ans=s.substr(i+1,j-i-1);
        }
        for(int index=1;index<n;index++){
            int i=index-1;
            int j=index;
            while(i>=0 && j<n && s[i]==s[j]){
                i--;
                j++;
            }
            if(j-i-1>ans.size())
                ans=s.substr(i+1,j-i-1);
        }
        return ans;
    }
};