//Binary Search
int searchInsert(vector<int>& nums, int target) {
    int i=0;
    int j=nums.size();
    while(i<j){
        int mid=(i+j)/2;
        if(nums[mid]<target)
            i=mid+1;
        else
            j=mid;
    }
    return i;
}
