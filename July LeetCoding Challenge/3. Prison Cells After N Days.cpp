class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(N==0)
            return cells;
        vector<vector<int> >dp(64,vector<int>(8,0));
        for(int i=1;i<7;i++)
            dp[0][i]=(cells[i-1]==cells[i+1]);
        int i=1;
        while(i<N){
            for(int j=1;j<7;j++)
                dp[i][j]=(dp[i-1][j-1]==dp[i-1][j+1]);
            if(dp[i]==dp[0])
                return dp[(N-1)%i];
            i++;
        }
        return dp[N-1];
    }
};
