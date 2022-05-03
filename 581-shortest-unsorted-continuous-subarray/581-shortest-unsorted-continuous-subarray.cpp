class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int start=n;
        int end=-1;
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>nums[i]){
                start=min(start,s.top());
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<nums[i]){
                end=max(end,s.top());
                s.pop();
            }
            s.push(i);
        }
        if(start==n)
            return 0;
        return end-start+1;
    }
};