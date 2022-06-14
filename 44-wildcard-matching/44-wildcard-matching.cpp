class Solution {
private:
    vector<vector<int>>mp;
    int fn(string &s, string &p, int i, int j){
        if(mp[i][j]!=2)
            return mp[i][j];
        if(i==s.size() && j==p.size())
            return mp[i][j]=1;
        if(j==p.size())
            return mp[i][j]=0;
        if(i==s.size()){
            for(int k=j;k<p.size();k++){
                if(p[k]!='*')
                    return mp[i][j]=0;
            }
            return mp[i][j]=1;
        }
        if(p[j]=='?')
            return mp[i][j]=fn(s,p,i+1,j+1);
        if(p[j]!='*'){
            if(s[i]==p[j])
                return mp[i][j]=fn(s,p,i+1,j+1);
            else
                return mp[i][j]=0;
        }
        for(int k=i;k<=s.size();k++){
            if(fn(s,p,k,j+1))
                return mp[i][j]=1;
        }
        return mp[i][j]=0;
    }
public:
    bool isMatch(string s, string p) {
        mp=vector<vector<int>>(s.size()+1,vector<int>(p.size()+1,2));
        return fn(s,p,0,0)==1?true:false;
    }
};