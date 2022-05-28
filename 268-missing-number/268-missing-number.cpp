class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int size=nums.size();
        int req=size*(size+1)/2;
        for(int i=0;i<size;i++)
            sum+=nums[i];
        return req-sum;
    }
};