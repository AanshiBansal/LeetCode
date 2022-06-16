class Solution {
private:
    // void binarySearch(vector<int>&ans,int low, int high, int num){
    //     if(low>high){
    //         if(low<ans.size())
    //             ans[low]=num;
    //         else
    //             ans.push_back(num);
    //         return;
    //     }
    //     int mid=(low+high)/2;
    //     if(ans[mid]<num){
    //         binarySearch(ans,mid+1,high,num);
    //     }else{
    //         binarySearch(ans,low,mid-1,num);
    //     }
    // }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        //ans.push_back(nums[0]);
        for(int i=0;i<n;i++){
            auto index=lower_bound(ans.begin(),ans.end(),nums[i]);
            if(index==ans.end())
                ans.push_back(nums[i]);
            else
                *index=nums[i];
            //binarySearch(ans,0,ans.size()-1,nums[i]);
        }
        return ans.size();
    }
};

// DP - Memorization
/*
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
*/

// f(index,prev)=max(f(index+1,prev),f(index+1,index)+1);
/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n));
        dp[n-1][0]=1;
        for(int j=1;j<n;j++){
            if(nums[j-1]<nums[n-1]){
                dp[n-1][j]=1;
            }else
                dp[n-1][j]=0;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=dp[i+1][j];
                if(j==0 || nums[j-1]<nums[i]){
                    dp[i][j]=max(dp[i][j],dp[i+1][i+1]+1);
                }
            }
        }
        return dp[0][0];
    }
};
*/