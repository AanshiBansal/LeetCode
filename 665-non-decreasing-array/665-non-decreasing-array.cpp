class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        nums.insert(nums.begin(),INT_MIN);
        //nums.push_back(INT_MAX);
        bool flag=false;
        for(int i=2;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                if(flag==false){
                    if(nums[i-2]<=nums[i]){
                        nums[i-1]=nums[i];
                    }else{
                        nums[i]=nums[i-1];
                    }
                    flag=true;
                }
                else
                    return false;
            }
        }
        return true;
    }
};