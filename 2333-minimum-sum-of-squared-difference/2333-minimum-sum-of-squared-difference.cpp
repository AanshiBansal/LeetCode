class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans=0;
        vector<int>diff(100001,0);
        int diffM=0;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            diff[abs(nums1[i]-nums2[i])]++;
            diffM=max(diffM,abs(nums1[i]-nums2[i]));
        }
        int total=k1+k2;
        int index=diffM;
        while(total>0 && index>0){
            int change=min(total,diff[index]);
            diff[index]-=change;
            diff[index-1]+=change;
            total-=change;
            index--;
        }
        for(int i=1;i<=diffM;i++){
            long long curr=i;
            curr*=i;
            curr*=diff[i];
            ans+=curr;
        }
        return ans;
    }
};