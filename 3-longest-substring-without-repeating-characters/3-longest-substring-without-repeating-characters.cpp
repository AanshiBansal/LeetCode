class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,-1);
        int n=s.size();
        int ans=0;
        int start=0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]<start){
                mp[s[i]]=i;
            }else{
                ans=max(ans,i-start);
                start=mp[s[i]]+1;
                mp[s[i]]=i;
            }
        }
        ans=max(ans,n-start);
        return ans;
    }
};