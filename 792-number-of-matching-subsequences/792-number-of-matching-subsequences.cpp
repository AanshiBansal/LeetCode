class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,set<int> >mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].insert(i);
        }
        int ans=0;
        for(string word:words){
            int posS=-1;
            int i=0;
            for(;i<word.size();i++){
                if(mp[word[i]].upper_bound(posS)!=mp[word[i]].end() && *mp[word[i]].upper_bound(posS)<s.size()){
                    posS=*mp[word[i]].upper_bound(posS);
                    //cout<<word<<" "<<posS<<endl;
                }else{
                    break;
                }
            }
            if(i==word.size())
                ans++;
        }
        return ans;
    }
};