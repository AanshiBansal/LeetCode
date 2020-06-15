vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int> >div(nums.size(),vector<int>());
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<i;j++)
            if(nums[i]%nums[j]==0 && div[j].size()>div[i].size())
                div[i]=div[j];
        div[i].push_back(nums[i]);
        if(div[i].size()>ans.size())
            ans=div[i];
    }
    return ans;
}
