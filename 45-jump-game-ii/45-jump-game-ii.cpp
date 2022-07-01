class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int start=0;
        int maxReach=0;
        while(maxReach<nums.size()-1){
            jumps++;
            int next=0;
            for(int i=start;i<=maxReach;i++){
                next=max(next,i+nums[i]);
            }
            start=maxReach+1;
            maxReach=next;
        }
        return jumps;
    }
};