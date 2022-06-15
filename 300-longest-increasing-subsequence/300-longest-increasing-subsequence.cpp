// class Solution {
// private:
//     void binarySearch(vector<int>&ans,int low, int high, int num){
//         if(low>high){
//             if(low<ans.size())
//                 ans[low]=num;
//             else
//                 ans.push_back(num);
//             return;
//         }
//         int mid=(low+high)/2;
//         if(ans[mid]<num){
//             binarySearch(ans,mid+1,high,num);
//         }else{
//             binarySearch(ans,low,mid-1,num);
//         }
//     }
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>ans;
//         for(int i=0;i<n;i++){
//             binarySearch(ans,0,ans.size()-1,nums[i]);
//         }
//         return ans.size();
//     }
// };
class Solution {
private:
    vector<vector<int>>dp;
private:
    int dfs(vector<int>& nums, int index, int prev){
        if(index==nums.size())
            return 0;
        if(dp[index][prev+1]!=-1)
            return dp[index][prev+1];
        if(prev!=-1 && nums[prev]>=nums[index])
            return dp[index][prev+1]=dfs(nums,index+1,prev);
        return dp[index][prev+1]=max(dfs(nums,index+1,index)+1,dfs(nums,index+1,prev));
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        dp=vector<vector<int>>(nums.size(),vector<int>(nums.size(),-1));
        return dfs(nums,0,-1);
    }
};