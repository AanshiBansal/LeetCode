class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int ans=0;
        int sol=0;
        int i=0;
        int j=tokens.size()-1;
        while(i<=j && (tokens[i]<=power || ans>0)){
            while(i<=j && tokens[i]<=power){
                ans++;
                power-=tokens[i];
                i++;
            }
            sol=max(ans,sol);
            if(j>=i && ans>0){
                ans--;
                power+=tokens[j];
                j--;
            }
        }
        return sol;
    }
};