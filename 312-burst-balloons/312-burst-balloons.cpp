// class Solution {
// private:
//     int fn(vector<int>& nums, int start, int end, vector<vector<int>>&dp){
//         if(start>end)
//             return 0;
//         if(dp[start][end]!=-1)
//             return dp[start][end];
//         int maxi=0;
//         int prev=start-1>=0?nums[start-1]:1;
//         int next=end+1<nums.size()?nums[end+1]:1;
//         for(int i=start;i<=end;i++){
//             maxi=max(maxi,nums[i]*prev*next+fn(nums,start,i-1,dp)+fn(nums,i+1,end,dp));
//         }
//         return dp[start][end]=maxi;
//     }
// public:
//     int maxCoins(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return fn(nums,0,n-1,dp);
//     }
// };

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int maxi=0;
                int prev=nums[i-1];
                int next=nums[j+1];
                for(int k=i;k<=j;k++){
                    maxi=max(maxi,nums[k]*prev*next+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};