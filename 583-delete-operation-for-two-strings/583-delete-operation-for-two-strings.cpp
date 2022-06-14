class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<int>prev(n+1,0);
        for(int i=0;i<=n;i++)
            prev[i]=i;
        vector<int>curr(n+1);
        for(int i=1;i<=m;i++){
            curr[0]=i;
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=prev[j-1];
                }else{
                    curr[j]=min(prev[j],curr[j-1])+1;
                }
            }
            prev=curr;
        }
        return curr[n];
    }
};