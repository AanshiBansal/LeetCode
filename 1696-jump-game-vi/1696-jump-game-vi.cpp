class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.size()==1)
            return nums[0];
        
        multiset<int>Q;
        Q.insert(nums[0]);
        
        for(int i = 1;i<nums.size();i++){
            if(Q.size()>k){
                auto it = Q.find(nums[i-k-1]);
                Q.erase(it);
            }
            nums[i] += *Q.rbegin();
            Q.insert(nums[i]);
        }
        
        return nums[nums.size()-1];
    }
};