class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int start=-1;
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()||mp[nums[i]]<start){
                mp[nums[i]]=i;
            }else{
                ans=max(ans,nums[i-1]-(start<1?0:nums[start-1]));
                start=mp[nums[i]]+1;
                mp[nums[i]]=i;
            }
            if(i>0)
            nums[i]+=nums[i-1];
        }
        ans=max(ans,nums[n-1]-(start<1?0:nums[start-1]));
        return ans;
    }
};