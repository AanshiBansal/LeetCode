class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=0;i-j>=0 && i+j<n; j++){
                if(s[i-j]==s[i+j])
                    ans++;
                else
                    break;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;i-j>=0 && i+j+1<n; j++){
                if(s[i-j]==s[i+j+1])
                    ans++;
                else
                    break;
            }
        }
        return ans;
    }
};