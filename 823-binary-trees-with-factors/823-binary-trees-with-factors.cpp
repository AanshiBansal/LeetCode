class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod=1000000007;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        unordered_map<int,long long>mp;
        long long ans=0;
        for(int i=0;i<n;i++){
            mp[arr[i]]=1;
            for(int j=0;j<i;j++){
                int other=arr[i]/arr[j];
                if(other*arr[j]==arr[i] && mp.find(other)!=mp.end()){
                    mp[arr[i]]+=(mp[arr[j]]*mp[other]);
                    mp[arr[i]]%=mod;
                }
            }
            ans+=mp[arr[i]];
            ans%=mod;
        }
        return ans;
    }
};