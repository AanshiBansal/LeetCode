class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(int i=s.size()-1;i>=0;i--){
            if(mp.find(s[i])==mp.end())
                mp[s[i]]=i;
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==i)
                return i;
            else
                mp[s[i]]=i;
        }
        return -1;
    }
};