class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans=INT_MAX;
        for(int num:nums){
            if(abs(num)<abs(ans)){
                ans=num;
            }
            if(abs(num)==abs(ans)){
                ans=max(ans,num);
            }
        }
        return ans;
    }
};