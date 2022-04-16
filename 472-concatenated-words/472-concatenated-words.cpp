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
    bool wordBreak(string s, unordered_set<string>& dict) {
        if(s.size()<2)
            return false;
        dict.erase(s);
        int n=s.size();
        vector<int>mp(n,2);
        bool ans=rec(s,0,n,dict,mp);
        dict.insert(s);
        return ans;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>dict(words.begin(),words.end());
        vector<string>ans;
        for(string w:words){
            if(wordBreak(w,dict))
                ans.push_back(w);
        }
        return ans;
    }
};