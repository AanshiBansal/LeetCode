// class Solution {
// public:
//     int maxCoins(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1)
//             return nums[0];
//         int ans=0;
//         vector<pair<int,int>>lr(n);
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//         for(int i=1;i<n-1;i++){
//             lr[i]={i-1,i+1};
//             pq.push({nums[i],i});
//         }
//         while(!pq.empty()){
//             int index=pq.top().second;
//             pq.pop();
//             cout<<index<<" "<<lr[index].first<<" "<<lr[index].second<<endl;
//             lr[lr[index].first].second=lr[index].second;
//             lr[lr[index].second].first=lr[index].first;
//             ans+=(nums[index]*nums[lr[index].first]*nums[lr[index].second]);
//             //cout<<ans<<endl;
//         }
//         ans+=(max(nums[0],nums[n-1])*(min(nums[0],nums[n-1])+1));
//         return ans;
//     }
// };

class Solution {
private:
    int fn(vector<int>& nums, int start, int end, vector<vector<int>>&dp){
        if(start>end)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        // if(start==end)
        //     return dp[start][end]=nums[start];
        int maxi=0;
        int prev=start-1>=0?nums[start-1]:1;
        int next=end+1<nums.size()?nums[end+1]:1;
        for(int i=start;i<=end;i++){
            maxi=max(maxi,nums[i]*prev*next+fn(nums,start,i-1,dp)+fn(nums,i+1,end,dp));
        }
        return dp[start][end]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fn(nums,0,n-1,dp);
    }
};