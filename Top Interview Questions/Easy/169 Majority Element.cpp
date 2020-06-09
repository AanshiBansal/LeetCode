//Moore's Voting Algorithm
int majorityElement(vector<int>& nums) {
    int count=0;
    int index=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==nums[index])
            count++;
        else
            count--;
        if(count==0){
            index=i+1;
            count=0;
        } 
    }
    //element does not exist
    if(index==nums.size())
        return -1;
    count=0;
    for(int i=0;i<nums.size();i++)
        if(nums[i]==nums[index])
            count++;
    if(count>nums.size()/2)
        return nums[index];
    else
        return -1;
}
