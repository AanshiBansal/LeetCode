class Solution {
    private:
    void merge(vector<pair<int,int>>& nums,int start, int mid, int end){
        vector<pair<int,int>>temp;
        int i=start;
        int j=mid+1;
        while(i<=mid && j<=end){
            if(nums[i].first<nums[j].first)
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
    void customFn(vector<pair<int,int>>& nums, int start, int mid, int end, vector<int>&ans){
        int i=start;
        int j=mid+1;
        while(i<=mid){
            while(j<=end && nums[i].first>nums[j].first){
                j++;
            }
            ans[nums[i].second]+=j-(mid+1);
            i++;
        }
        return;
    }
    void mergeSort(vector<pair<int,int>>& nums, int start, int end, vector<int>&ans){
        if(start>=end)
            return;
        int mid=(start+end)/2;
        mergeSort(nums,start,mid,ans);
        mergeSort(nums,mid+1,end,ans);
        customFn(nums,start,mid,end,ans);
        merge(nums,start,mid,end);
        return;
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        vector<pair<int,int>>num(n);
        for(int i=0;i<n;i++)
            num[i]={nums[i],i};
        mergeSort(num,0,n-1,ans);
        return ans;
    }
};