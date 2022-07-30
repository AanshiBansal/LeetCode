class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        int m=words1.size();
        int n=words2.size();
        
        vector<int>mp2(26,0);
        for(int i=0;i<n;i++){
            vector<int>temp(26,0);
            for(auto c:words2[i]){
                temp[c-'a']++;
            }
            for(int j=0;j<26;j++)
                mp2[j]=max(mp2[j],temp[j]);
        }
        
        for(int i=0;i<m;i++){
            bool flag=true;
            vector<int>mp1(26,0);
            for(auto c:words1[i])
                mp1[c-'a']++;
            for(int k=0;k<26;k++){
                if(mp1[k]<mp2[k]){
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(words1[i]);
        }
        return ans;
    }
};