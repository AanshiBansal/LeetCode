// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         int ans=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]==nums[j])
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };

/*class Solution {
private:
    void merge(vector<int>&nums, int start, int mid, int end){
        vector<int>temp;
        int i=start, j=mid+1;
        while(i<=mid && j<=end){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=end){
            temp.push_back(nums[j++]);
        }
        for(int i=0;i<temp.size();i++){
            nums[i+start]=temp[i];
        }
    }
    int customFn(vector<int>&nums, int start, int mid, int end){
        int ans=0;
        int i=start,j=mid+1;
        int prev=INT_MIN;
        int count=0;
        while(i<=mid){
            if(nums[i]==prev){
                ans+=count;
                i++;
                continue;
            }
            count=0;
            while(j<=end && nums[j]<nums[i]){
                j++;
            }
            while(j<=end && nums[j]==nums[i]){
                j++;
                count++;
            }
            ans+=count;
            prev=nums[i];
            i++;
        }
        return ans;
    }
    int mergeSort(vector<int>&nums, int start, int end){
        if(start>=end)
            return 0;
        int mid = start+(end-start)/2;
        int first=mergeSort(nums,start,mid);
        int second=mergeSort(nums,mid+1,end);
        int curr=customFn(nums,start,mid,end);
        merge(nums,start,mid,end);
        return first+curr+second;
    }
public:
    int numIdenticalPairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int>c(101,0);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=c[nums[i]]++;
        }
        return ans;
    }
};