// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int tortoise=nums[0];
//         int hare=nums[0];
//         do{
//             hare=nums[nums[hare]];
//             tortoise=nums[tortoise];
//         }while(hare!=tortoise);
//         hare=nums[0];
//         while(hare!=tortoise){
//             hare=nums[hare];
//             tortoise=nums[tortoise];
//         }
//         return tortoise;
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=1;
        int high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            int count=0;
            for(int num:nums){
                if(num<=mid)
                    count++;
            }
            if(count>mid){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};