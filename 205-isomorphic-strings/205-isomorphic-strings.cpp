class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,char>mp;
        unordered_set<char>taken;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                if(taken.find(t[i])!=taken.end())
                    return false;
                mp[s[i]]=t[i];
                taken.insert(t[i]);
            }
            if(t[i]!=mp[s[i]])
                return false;
        }
        return true;
    }
};