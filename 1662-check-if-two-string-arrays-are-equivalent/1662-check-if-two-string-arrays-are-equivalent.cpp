class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        vector<unordered_set<int>>mp(26);
        int itr=0;
        for(int i=0;i<word1.size();i++){
            for(int j=0;j<word1[i].size();j++){
                mp[word1[i][j]-'a'].insert(itr++);
            }
        }
        int itr2=0;
        for(int i=0;i<word2.size();i++){
            for(int j=0;j<word2[i].size();j++){
                if(mp[word2[i][j]-'a'].find(itr2++)==mp[word2[i][j]-'a'].end())
                    return false;
            }
        }
        return itr==itr2;
    }
};