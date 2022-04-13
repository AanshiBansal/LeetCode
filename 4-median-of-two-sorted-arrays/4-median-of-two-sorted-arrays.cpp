class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int n=nums1.size();
        int m=nums2.size();
        // Size of first half of combined arrays
        int size=(n+m+1)/2;
        int low=max(0,size-m-1);
        int high=min(size-1,n-1);
        while(low<=high){
            int mid=(low+high)/2;
            int s1=mid+1;
            int s2=size-s1;
            int l1=s1-1>=0 ? nums1[s1-1] : INT_MIN;
            int l2=s2-1>=0 ? nums2[s2-1] : INT_MIN;
            int r1=s1 < n ? nums1[s1] : INT_MAX;
            int r2=s2 < m ? nums2[s2] : INT_MAX;
            if(l1<=r2 && l2<=r1){
                if((m+n)%2==0)
                    return double(max(l1,l2)+min(r1,r2))/2;
                return max(l1,l2);
            }
            if(l1>r2){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        int l1=INT_MIN,l2=nums2[size-1],r1=0<n?nums1[0]:INT_MAX,r2=size<m?nums2[size]:INT_MAX;
        if((m+n)%2==0){
            return double(max(l1,l2)+min(r1,r2))/2;
        }
        return max(l1,l2);
    }
};