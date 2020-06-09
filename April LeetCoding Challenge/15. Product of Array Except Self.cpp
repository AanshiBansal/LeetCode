vector<int> productExceptSelf(vector<int>& nums) {
    vector<int>sol(nums.size());
    int temp=1;
    for(int i=0;i<nums.size();i++){
        sol[i]=temp;
        temp*=nums[i];
    }
    temp=1;
    for(int i=nums.size()-1;i>=0;i--){
        sol[i]*=temp;
        temp*=nums[i];
    }
    return sol;
}
