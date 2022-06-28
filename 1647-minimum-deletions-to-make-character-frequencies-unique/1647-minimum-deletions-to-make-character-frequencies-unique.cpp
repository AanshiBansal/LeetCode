class Solution {
public:
    int minDeletions(string s) {
        vector<int>count(26,0);
        for(char c:s){
            count[c-'a']++;
        }
        sort(count.begin(),count.end());
        int prev=count[25];
        int ans=0;
        for(int i=24;i>=0 && count[i]!=0;i--){
            if(count[i]<prev){
                prev=count[i];
            }else{
                prev=max(prev-1,0);
                ans+=count[i]-prev;
            }
        }
        return ans;
    }
};