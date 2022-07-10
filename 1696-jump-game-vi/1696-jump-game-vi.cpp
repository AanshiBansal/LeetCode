// class Solution {
// public:
//     int maxResult(vector<int>& nums, int k) {
//         if(nums.size()==1)
//             return nums[0];
        
//         multiset<int>Q;
//         Q.insert(nums[0]);
        
//         for(int i = 1;i<nums.size();i++){
//             if(Q.size()>k){
//                 auto it = Q.find(nums[i-k-1]);
//                 Q.erase(it);
//             }
//             nums[i] += *Q.rbegin();
//             Q.insert(nums[i]);
//         }
        
//         return nums[nums.size()-1];
//     }
// };

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        deque<int>q;
        q.push_back(0);
        for(int i=1;i<n;i++){
            if(q.front()==i-k-1)
                q.pop_front();
            nums[i]+=nums[q.front()];
            while(!q.empty() && nums[q.back()]<nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return nums[n-1];
    }
};