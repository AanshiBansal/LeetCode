class Solution {
public:
    int robI(vector<int>nums, int start, int end) {
        int n=nums.size();
        if(n==0 || end<start)
            return 0;
        if(start==end)
            return nums[start];
        nums[start+1]=max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++)
            nums[i]=max(nums[i-1],nums[i-2]+nums[i]);
        return nums[end];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        return max(robI(nums,0,nums.size()-2),robI(nums,1,nums.size()-1));
    }
};