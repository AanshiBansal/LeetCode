class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        int ans=0;
        for(auto itr:mp){
            ans+=itr.second;
            if(itr.second%2==1)
                ans--;
        }
        if(ans!=s.size())
            ans++;
        return ans;
    }
};