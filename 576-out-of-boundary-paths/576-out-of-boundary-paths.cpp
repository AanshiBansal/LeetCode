typedef long long ll;
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove==0)
            return 0;
        int dc[]={-1,0,1,0};
        int dr[]={0,-1,0,1};
        queue<pair<int,int>>q;
        q.push({startRow,startColumn});
        vector<vector<ll>>total(m,vector<ll>(n,0));
        total[startRow][startColumn]=1;
        vector<vector<ll>>prev(m,vector<ll>(n,0));
        prev[startRow][startColumn]=1;
        int moves=1;
        int mod=1000000007;
        while(moves<maxMove){
            int size=q.size();
            vector<vector<ll>>curr(m,vector<ll>(n,0));
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
                        curr[r+dr[j]][c+dc[j]]%=mod;
                    }
                }
            }
            moves++;
            prev=curr;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    total[i][j]+=prev[i][j];
                    total[i][j]%=mod;
                }
            }
        }
        long long ans=0;
        for(int j=0;j<n;j++){
            ans+=total[0][j];
            ans%=mod;
            ans+=total[m-1][j];
            ans%=mod;
        }
        for(int i=0;i<m;i++){
            ans+=total[i][0];
            ans%=mod;
            ans+=total[i][n-1];
            ans%=mod;
        }
        return ans;
    }
};