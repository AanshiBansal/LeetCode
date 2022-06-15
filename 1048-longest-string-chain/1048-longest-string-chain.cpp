class Solution {
private:
    unordered_map<string,int>mp;
    bool check(string &a, string &b){
        bool extra=false;
        int i=0,j=0;
        while(i<a.size()){
            if(a[i]==b[j]){
                i++;j++;
            }else{
                if(extra)
                    return false;
                extra=true;
                j++;
            }
        }
        return true;
    }
    int dfs(vector<string>& words, string word){
        if(mp.find(word)!=mp.end())
            return mp[word];
        int size=word.size();
        int ans=0;
        for(int i=0;i<words.size();i++){
            if(words[i].size()==size+1 && check(word,words[i])){
                ans=max(ans,dfs(words,words[i]));
            }
        }
        return mp[word]=ans+1;
    }
public:
    int longestStrChain(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            ans=max(ans,dfs(words,words[i]));
        }
        return ans;
    }
};