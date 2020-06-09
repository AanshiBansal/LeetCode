int titleToNumber(string s) {
    int ans=0;
    for(int i=0;i<s.size();i++){
        ans*=26;
        int alph=s[i]-'A'+1;
        ans+=alph;
    }
    return ans;
}
