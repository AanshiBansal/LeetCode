class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        vector<int>dp=nums;
        dp[0]=0;
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        nums[n-1]=0;
        nums[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
            nums[i]=max(nums[i-1],nums[i-2]+nums[i]);
        return max(nums[n-1],dp[n-1]);
    }
};