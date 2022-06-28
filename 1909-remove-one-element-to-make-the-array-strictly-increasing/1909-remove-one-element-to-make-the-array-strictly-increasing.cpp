class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        nums.insert(nums.begin(),INT_MIN);
        bool flag=false;
        int n=nums.size();
        for(int i=2;i<n;i++){
            if(nums[i]<=nums[i-1]){
                if(flag==false){
                    flag=true;
                    if(nums[i]>nums[i-2]){
                        nums[i-1]=nums[i-2];
                    }else{
                        nums[i]=nums[i-1];
                        nums[i-1]=nums[i-2];
                    }
                }else
                    return false;
            }
        }
        return true;
    }
};