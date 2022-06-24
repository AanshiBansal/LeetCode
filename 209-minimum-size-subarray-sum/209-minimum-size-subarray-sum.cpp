class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(sum<target){
            return 0;
        }
        int low=1;
        int high=nums.size();
        while(low<high){
            int mid=(low+high)/2;
            int curr=0;
            bool flag=false;
            for(int i=0;i<mid;i++){
                curr+=nums[i];
            }
            for(int i=0;i+mid<nums.size();i++){
                if(curr>=target){
                    break;
                    flag=true;
                }else{
                    curr-=nums[i];
                    curr+=nums[i+mid];
                }
            }
            if(curr>=target){
                flag=true;
            }
            if(flag){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};