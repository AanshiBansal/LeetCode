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

//An extension of this problem is to apply such updates on an array where all elements are not the same.
// apply reverse partial_sum operation on the array (for example, array [2, 3, 10, 5][2,3,10,5] transforms to [2, 1, 7, -5][2,1,7,−5]) as an initialization step and then proceed 