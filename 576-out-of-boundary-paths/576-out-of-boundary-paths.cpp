class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove==0)
            return 0;
        int dc[]={-1,0,1,0};
        int dr[]={0,-1,0,1};
        queue<pair<int,int>>q;
        q.push({startRow,startColumn});
        vector<vector<long long>>total(m,vector<long long>(n,0));
        total[startRow][startColumn]=1;
        vector<vector<long long>>prev(m,vector<long long>(n,0));
        prev[startRow][startColumn]=1;
        int moves=1;
        while(moves<maxMove){
            int size=q.size();
            vector<vector<long long>>curr(m,vector<long long>(n,0));
            for(int i=0;i<size;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    if(r+dr[j]>=0 && r+dr[j]<m && c+dc[j]>=0 && c+dc[j]<n){
                        if(curr[r+dr[j]][c+dc[j]]==0){
                            q.push({r+dr[j],c+dc[j]});
                        }
                        curr[r+dr[j]][c+dc[j]]+=prev[r][c];
                        curr[r+dr[j]][c+dc[j]]%=1000000007;
                    }
                }
            }
            moves++;
            prev=curr;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    total[i][j]+=prev[i][j];
                    total[i][j]%=1000000007;
                }
            }
        }
        long long ans=0;
        for(int j=0;j<n;j++){
            ans+=total[0][j];
            ans%=1000000007;
            ans+=total[m-1][j];
            ans%=1000000007;
        }
        for(int i=0;i<m;i++){
            ans+=total[i][0];
            ans%=1000000007;
            ans+=total[i][n-1];
            ans%=1000000007;
        }
        return ans;
    }
};