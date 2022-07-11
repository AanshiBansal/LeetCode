class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>prevS(n);
        vector<int>nextS(n);
        vector<long long>prefixSum(n);
        long long prev=0;
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && nums[s.top()]>=nums[i]){
                s.pop();
            }
            prevS[i]=s.top();
            s.push(i);
            prefixSum[i]=prev+nums[i];
            prev=prefixSum[i];
        }
        while(!s.empty()){
            s.pop();
        }
        s.push(n);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=n && nums[s.top()]>=nums[i]){
                s.pop();
            }
            nextS[i]=s.top();
            s.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long sum=prefixSum[nextS[i]-1]-prefixSum[prevS[i]+1]+nums[prevS[i]+1];
            ans=max(ans,sum*nums[i]);
        }
        return ans%1000000007;
    }
};