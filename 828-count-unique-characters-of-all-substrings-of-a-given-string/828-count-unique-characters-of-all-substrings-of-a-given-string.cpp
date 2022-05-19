class Solution {
public:
    int uniqueLetterString(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<26;i++){
            char c='A'+i;
            int curr=-1;
            int prev=-1;
            for(int j=0;j<=n;j++){
                if(j==n || s[j]==c){
                    if(curr!=-1){
                        ans+=((curr-prev)*(j-curr));
                    }
                    prev=curr;
                    curr=j;
                }
            }
        }
        return ans;
    }
};