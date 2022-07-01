class Solution {
private:
    void merge(vector<int>& nums,int start, int mid, int end){
        vector<int>temp;
        int i=start;
        int j=mid+1;
        while(i<=mid && j<=end){
            if(nums[i]<nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
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
    int customFn(vector<int>& nums, int start, int mid, int end){
        int i=start;
        int j=mid+1;
        int ans=0;
        while(i<=mid){
            while(j<=end && nums[i]>2*(long)nums[j]){
                j++;
            }
            ans+=j-mid-1;
            i++;
        }
        return ans;
    }
    int mergeSort(vector<int>& nums, int start, int end){
        if(start>=end)
            return 0;
        int mid=(start+end)/2;
        int first=mergeSort(nums,start,mid);
        int second=mergeSort(nums,mid+1,end);
        int curr=customFn(nums,start,mid,end);
        merge(nums,start,mid,end);
        return first+second+curr;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};