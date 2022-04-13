class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        int j=i+1;
        if(i>=0){
            while(j<nums.size() && nums[j]>nums[i]){
                j++;
            }
            swap(nums[i],nums[j-1]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};