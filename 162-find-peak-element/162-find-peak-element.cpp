class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            //cout<<low<<" "<<high<<" "<<mid<<endl;
            if(mid==nums.size()-1)
                return mid;
            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    }
};