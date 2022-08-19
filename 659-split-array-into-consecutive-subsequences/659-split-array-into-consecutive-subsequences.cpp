class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>prev;
        for(int i=0;i<nums.size();i++){
            int count=1;
            if(i>0 && nums[i]!=nums[i-1]+1){
                prev=priority_queue<int,vector<int>,greater<int>>();
            }
            while(i+1<nums.size() && nums[i]==nums[i+1]){
                count++;
                i++;
            }
            priority_queue<int,vector<int>,greater<int>>curr;
            while(!prev.empty() && count>0){
                curr.push(prev.top()+1);
                prev.pop();
                count--;
            }
            if(!prev.empty() && prev.top()<3){
                return false;
            }
            while(count>0){
                curr.push(1);
                count--;
            }
            prev=curr;
            if((i+1==nums.size() || nums[i+1]!=nums[i]+1) && prev.top()<3)
                return false;
        }
        return true;
    }
};