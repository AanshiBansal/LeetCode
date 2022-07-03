class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        int ans=0;
        int n=nums.size();
        // int prev=nums[0];
        int i=0;
        while(i<n-1 && nums[i]==nums[i+1]){
            i++;
        }
        if(i!=n-1)
            ans++;
        int prev=nums[i];
        for(;i<n-1;i++){
            if(nums[i]==nums[i+1])
                continue;
            if(nums[i]>prev && nums[i]>nums[i+1])
                ans++;
            if(nums[i]<prev && nums[i]<nums[i+1])
                ans++;
            prev=nums[i];
        }
        if(nums[n-1]!=prev)
            ans++;
        return max(ans,1);
    }
};