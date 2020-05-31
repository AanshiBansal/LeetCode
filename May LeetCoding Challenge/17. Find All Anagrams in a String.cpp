class Solution {
public:
    bool check(vector<int>&a,vector<int>&b){
        for(int i=0;i<26;i++)
            if(a[i]!=b[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size())
            return ans;
        vector<int>pc(26,0);
        for(int i=0;i<p.size();i++){
            pc[p[i]-'a']++;
        }
        vector<int>sc(26,0);
        for(int i=0;i<p.size();i++){
            sc[s[i]-'a']++;
        }
        if(check(pc,sc))
            ans.push_back(0);
        int prev=0;
        for(int i=p.size();i<s.size();i++){
            sc[s[prev++]-'a']--;
            sc[s[i]-'a']++;
            if(check(pc,sc))
                ans.push_back(prev);
        }
        return ans;
    }
};
