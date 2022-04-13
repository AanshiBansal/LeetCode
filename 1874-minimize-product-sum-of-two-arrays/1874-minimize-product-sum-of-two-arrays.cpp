class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        vector<int>c1(101,0);
        vector<int>c2(101,0);
        int n=nums1.size();
        for(int i=0;i<n;i++){
            c1[nums1[i]]++;
            c2[nums2[i]]++;
        }
        int p1=0;
        int p2=100;
        int count=0;
        int ans=0;
        while(count<n){
            while(c1[p1]==0){
                p1++;
            }
            while(c2[p2]==0){
                p2--;
            }
            ans+=(p1*p2);
            c1[p1]--;
            c2[p2]--;
            count++;
        }
        
        return ans;
    }
};