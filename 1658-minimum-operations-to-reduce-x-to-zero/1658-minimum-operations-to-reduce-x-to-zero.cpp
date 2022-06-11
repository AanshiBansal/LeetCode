class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s=nums.size();
        int ans=INT_MAX;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int prefixSum=0;
        for(int i=0;i<s;i++){
            prefixSum+=nums[i];
            mp[prefixSum]=i;
        }
        if(mp.find(prefixSum-x)!=mp.end())
            ans=s-1-mp[prefixSum-x];
        for(int i=0;i<s;i++){
            prefixSum+=nums[i];
            if(mp.find(prefixSum-x)!=mp.end())
                ans=min(ans,i+s-mp[prefixSum-x]);
        }
    
        if(ans>s)
            return -1;
        return ans;
    }
};