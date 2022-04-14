class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int>ans(length,0);
        for(auto update:updates){
            ans[update[0]]+=update[2];
            if(update[1]+1<length)
                ans[update[1]+1]-=update[2];
        }
        for(int i=1;i<length;i++)
            ans[i]+=ans[i-1];
        return ans;
    }
};