bool fn(string &a,string &b){
    return a.size()<b.size();
}
class Solution {
private:
    //unordered_map<string,int>mp;
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
    // int dfs(vector<string>& words, string word, int index){
    //     if(mp.find(word)!=mp.end())
    //         return mp[word];
    //     int size=word.size();
    //     int ans=0;
    //     for(int i=index+1;i<words.size() && words[i].size()<=size+1;i++){
    //         if(words[i].size()==size+1 && check(word,words[i])){
    //             ans=max(ans,dfs(words,words[i],i));
    //         }
    //     }
    //     return mp[word]=ans+1;
    // }
public:
    // int longestStrChain(vector<string>& words) {
    //     int ans=0;
    //     sort(words.begin(),words.end(),fn);
    //     for(int i=0;i<words.size();i++){
    //         ans=max(ans,dfs(words,words[i],i));
    //     }
    //     return ans;
    // }
    int longestStrChain(vector<string>& words) {
        int ans=1;
        int n=words.size();
        vector<int>dp(n,1);
        sort(words.begin(),words.end(),fn);
        for(int i=n-2;i>=0;i--){
            int size=words[i].size();
            for(int j=i+1;j<words.size() && words[j].size()<=size+1;j++){
                if(words[j].size()==size+1 && check(words[i],words[j])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};