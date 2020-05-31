//Kadane's Algorithm
int maxSubArray(vector<int>& nums) {
   int ans = INT_MIN;
    int current = 0;
    for(int i=0;i<nums.size();i++){
        current = nums[i]>nums[i]+current?nums[i]:nums[i]+current;
        if(current>ans)
            ans= current;
    }
    return ans;
}
