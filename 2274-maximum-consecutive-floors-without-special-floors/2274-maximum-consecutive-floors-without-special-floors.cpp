class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int ans=0;
        int i=bottom;
        int itr=0;
        while(i<=top && itr<special.size()){
            ans=max(ans,special[itr]-i);
            i=special[itr]+1;
            itr++;
        }
        ans=max(ans,top-i+1);
        return ans;
    }
};