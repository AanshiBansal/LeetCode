class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        int n=words.size();
        if(n==0)
            return ans;
        ans.push_back(words[0]);
        vector<int>prev(26,0);
        for(int i=0;i<words[0].size();i++){
            prev[words[0][i]-'a']++;
        }
        for(int i=1;i<n;i++){
            vector<int>curr(26,0);
            for(int j=0;j<words[i].size();j++){
                curr[words[i][j]-'a']++;
            }
            int j=0;
            for(;j<26;j++){
                if(prev[j]!=curr[j]){
                    break;
                }
            }
            if(j!=26){
                ans.push_back(words[i]);
            }
            prev=curr;
        }
        return ans;
    }
};