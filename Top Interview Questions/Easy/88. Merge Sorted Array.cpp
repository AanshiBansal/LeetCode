void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int size=nums1.size()-1;
    for(int i=m-1;i>=0;i--)
        nums1[size--]=nums1[i];
    size++;
    int i=size,j=0,k=0;
    while(i<nums1.size() && j<n){
        if(nums1[i]<=nums2[j])
            nums1[k++]=nums1[i++];
        else
            nums1[k++]=nums2[j++];
    }
    while(j<n){
        nums1[k++]=nums2[j++];
    }
}
