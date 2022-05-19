class Solution {
public:
    int uniqueLetterString(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<26;i++){
            char curr='A'+i;
            int start=-1;
            int prev=-1;
            for(int j=0;j<n;j++){
                if(s[j]==curr){
                    if(start!=-1){
                        int a=(start-(prev+1)+1);
                        int b=(j-1-start+1);
                        //ans+=(j-1-(prev+1)+1);
                        ans+=(a*b);
                    }
                    //ans+=(j-(start+1)+1);
                    prev=start;
                    start=j;
                }
            }
            if(start!=-1){
                int a=(start-(prev+1)+1);
                int b=(n-1-start+1);
                ans+=(a*b);
            }
        }
        return ans;
    }
};