class Solution {
public:
    bool check(vector<int>&a,vector<int>&b){
        for(int i=0;i<26;i++)
            if(a[i]!=b[i])
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        vector<int>s1c(26,0);
        for(int i=0;i<s1.size();i++){
            s1c[s1[i]-'a']++;
        }
        vector<int>s2c(26,0);
        for(int i=0;i<s1.size();i++){
            s2c[s2[i]-'a']++;
        }
        if(check(s1c,s2c))
            return true;
        int prev=0;
        for(int i=s1.size();i<s2.size();i++){
            s2c[s2[prev++]-'a']--;
            s2c[s2[i]-'a']++;
            if(check(s2c,s1c))
                return true;
        }
        return false;
    }
};
