//Binary Search
int findDuplicate(vector<int>& nums) {
    int start=1;
    int end=nums.size()-1;
    while(start<end){
        int less=0;
        int more=0;
        int mid=(start+end)/2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=start && nums[i]<=mid)
                less++;
            if(nums[i]>mid && nums[i]<=end)
                more++;
        }
        if(less>more)
            end=mid;
        else
            start=mid+1;
    }
    return start;
}
