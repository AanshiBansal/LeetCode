class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int element=nums[0];
        for(int i=1;i<nums.size();i++){
            if(count==0 || element==nums[i]){
                element=nums[i];
                count++;
            }else{
                count--;
            }
        }
        return element;
    }
};