// Not a binary search solution
// Time: O(n)
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

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int left=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
//         int right=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
//         if(left==right)
//             return {-1,-1};
//         return {left,right-1};
//     }
// };

int lowerBound(vector<int>&a, int target){
    int low=0;
    int high=a.size();
    while(low<high){
        int mid=low+(high-low)/2;
        if(a[mid]>=target){
            high=mid;
        }else{
            low=mid+1;
        }
    }
    return low;
}

int upperBound(vector<int>&a, int target){
    int low=0;
    int high=a.size();
    while(low<high){
        int mid=low+(high-low)/2;
        if(a[mid]>target){
            high=mid;
        }else{
            low=mid+1;
        }
    }
    return low;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=lowerBound(nums,target);
        int right=upperBound(nums,target);
        if(left==right)
            return {-1,-1};
        return {left,right-1};
    }
};