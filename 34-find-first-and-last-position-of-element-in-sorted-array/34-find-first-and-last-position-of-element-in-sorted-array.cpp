// class Solution {
// private: 
//     void help(vector<int>&nums, int low,int high, int target, int &start, int &end){
//         if(high<low)
//             return;
//         int mid=(low+high)/2;
//         if(target==nums[mid]){
//             start=min(start,mid);
//             end=max(end,mid);
//         }
//         if(target<=nums[mid]){
//             help(nums,low,mid-1,target,start,end);
//         }
//         if(target>=nums[mid])
//             help(nums,mid+1,high,target,start,end);
//     }
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int low=0;
//         int high=nums.size()-1;
//         int start=INT_MAX;
//         int end=-1;
//         help(nums,low,high,target,start,end);
//         if(start==INT_MAX)
//             start=-1;
//         return {start,end};
//     }
// };

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int right=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(left==nums.size() || nums[left]!=target)
            return {-1,-1};
        return {left,right-1};
    }
};