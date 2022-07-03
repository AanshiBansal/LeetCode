class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int i=n/2;i>0;i--){
            if(n%i==0){
                bool ans=true;
                for(int j=0;j<n;j++){
                    if(s[j]!=s[j%i]){
                        ans=false;
                        break;
                    }
                }
                if(ans)
                    return true;
            }
        }
        return false;
    }
};