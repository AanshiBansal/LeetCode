class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(int num:nums){
            s.insert(num);
        }
        int ans=0;
        for(int num:nums){
            if(s.find(num-1)==s.end()){
                int curr=0;
                while(s.find(num)!=s.end()){
                    curr++;
                    num++;
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};