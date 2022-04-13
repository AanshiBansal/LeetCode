class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<=n-3;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int curr=nums[i]+nums[j]+nums[k];
                if(abs(target-curr)<abs(target-ans))
                    ans=curr;
                if(curr==target)
                    return target;
                if(curr<target)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};