class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        //vector<int>dp(n+1);
        //dp[0]=0;
        //dp[1];
        int prev=0;
        int prev2=0;
        int curr;
        for(int i=2;i<=n;i++){
            curr=min(prev+cost[i-1],prev2+cost[i-2]);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};