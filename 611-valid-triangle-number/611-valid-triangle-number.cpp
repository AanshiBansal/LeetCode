class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int left=i+1;
            int right=left+1;
            while(left<nums.size()){
                while(right<nums.size() && nums[i]+nums[left]>nums[right]){
                    right++;
                }
                ans+=max(0,right-left-1);
                left++;
            }
        }
        return ans;
    }
};