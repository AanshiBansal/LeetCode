class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=0;
        for(int num:nums)
            high=max(num,high);
        while(low<high){
            int mid=low+(high-low)/2;
            int curr=0;
            for(int num:nums){
                curr+=num/mid;
                if(num%mid!=0)
                    curr++;
            }
            if(curr>threshold){
                low=mid+1;
            }else
                high=mid;
        }
        return low;
    }
};