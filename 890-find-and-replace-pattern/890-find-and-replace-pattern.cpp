class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        int size=pattern.size();
        for(string word:words){
            unordered_set<char>s;
            unordered_map<char,char>mp;
            bool flag=true;
            for(int i=0;i<size;i++){
                if(mp.find(pattern[i])==mp.end() && s.find(word[i])==s.end()){
                    mp[pattern[i]]=word[i];
                    s.insert(word[i]);
                }
                if(mp[pattern[i]]!=word[i]){
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(word);
        }
        return ans;
    }
};