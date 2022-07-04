// class Solution {
// public:
//     int deleteAndEarn(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int prevNum1=-1;
//         int prev1=0;
//         int prevNum2=-2;
//         int prev2=0;
//         for(int i=0;i<nums.size();){
//             int currNum=nums[i];
//             int curr=0;
//             while(i<nums.size() && nums[i]==currNum){
//                 curr+=currNum;
//                 i++;
//             }
//             if(prevNum1==currNum-1){
//                 curr=max(prev1,curr+prev2);
//             }else{
//                 curr+=max(prev1,prev2);
//             }
//             prev2=prev1;
//             prevNum2=prevNum1;
//             prev1=curr;
//             prevNum1=currNum;
//         }
//         return max(prev1,prev2);
//     }
// };

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>dp(10001,0);
        for(int num:nums){
            dp[num]++;
        }
        for(int i=2;i<=10000;i++){
            dp[i]=max(dp[i]*i+dp[i-2],dp[i-1]);
        }
        return dp[10000];
    }
};