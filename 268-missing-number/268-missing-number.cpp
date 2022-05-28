class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum=0;
        long long size=nums.size();
        long long req=size*(size+1)/2;
        for(int i=0;i<size;i++)
            sum+=nums[i];
        return req-sum;
    }
};