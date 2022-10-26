class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // for(int i=0;i<nums.size();i++){
        //     int sum=nums[i];
        //     for(int j=i-1;j>=0;j--){
        //         sum+=nums[j];
        //         if(sum%k==0)
        //             return true;
        //     }
        // }
        // return false;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sum%=k;
            if(mp.find(sum)!=mp.end()){
                if(mp[sum]!=i-1)
                    return true;
            }
            else
                mp[sum]=i;
        }
        return false;
    }
};