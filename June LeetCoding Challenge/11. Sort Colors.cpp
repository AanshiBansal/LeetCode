void sortColors(vector<int>& nums) {
    int zero=0;
    int two=nums.size()-1;
    int i=0;
    while(i<=two){
        switch(nums[i]){
            case 0:{
                swap(nums[i++],nums[zero++]);
                break;
            }
            case 1:{
                i++;
                break;
            }
            case 2:{
                swap(nums[i],nums[two--]);
            }
        }
    }
}
