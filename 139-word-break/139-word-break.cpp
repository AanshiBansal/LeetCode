class Solution {
private:
    bool rec(string s, int index, int n, unordered_set<string>&dict, vector<int>&mp){
        if(index==n)
            return true;
        if(mp[index]==0)
            return false;
        if(mp[index]==1)
            return true;
        for(int i=index;i<n;i++){
            if(dict.find(s.substr(index,i-index+1))!=dict.end() && rec(s,i+1,n,dict,mp)){
                mp[index]=1;
                return true;
            }
        }
        mp[index]=0;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<int>mp(n,2);
        return rec(s,0,n,dict,mp);
    }
};