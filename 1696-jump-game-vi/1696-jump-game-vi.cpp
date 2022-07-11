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

// decreasing monoqueue
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        deque<pair<int,int>>q;
        q.push_back({0,nums[0]});
        for(int i=1;i<n;i++){
            if(q.front().first==i-k-1)
                q.pop_front();
            int curr = nums[i]+q.front().second;
            while(!q.empty() && q.back().second<curr){
                q.pop_back();
            }
            q.push_back({i,curr});
        }
        return q.back().second;
    }
};