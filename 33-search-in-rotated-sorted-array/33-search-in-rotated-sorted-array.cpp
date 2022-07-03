class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    }
    int search(vector<int>& nums, int target) {
        int partition=findMin(nums);
        int low=0;
        int high=partition-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        low=partition;
        high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
    }
};