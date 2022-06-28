class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum=0;
        for(int num:nums)
            sum+=num;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            sum-=nums[i];
            if(sum==curr)
                return i;
            curr+=nums[i];
        }
        return -1;
    }
};