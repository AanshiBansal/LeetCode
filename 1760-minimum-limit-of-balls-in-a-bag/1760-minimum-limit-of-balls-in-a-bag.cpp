class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=1000000000;
        while(low<high){
            int mid=low+(high-low)/2;
            int operations=0;
            for(int num:nums){
                operations+=(num/mid);
                if(num%mid==0)
                    operations--;
            }
            if(operations>maxOperations){
                low=mid+1;
            }else
                high=mid;
        }
        return low;
    }
};