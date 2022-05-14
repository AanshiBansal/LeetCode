class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        long long sum=0;
        long long curr=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        for(int i=0;i<n-1;i++){
            curr+=nums[i];
            sum-=nums[i];
            if(curr>=sum)
                ans++;
        }
        return ans;
    }
};