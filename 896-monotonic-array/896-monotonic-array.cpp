class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()<=2)
            return true;
        int i=0;
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        if(i==nums.size()-1)
            return true;
        if(nums[i+1]>nums[i]){
            for(;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1])
                    return false;
            }
            return true;
        }
        for(;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1])
                return false;
        }
        return true;
    }
};