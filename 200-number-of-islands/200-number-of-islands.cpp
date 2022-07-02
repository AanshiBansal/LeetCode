class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // int dr[]={-1,-1,-1,0,0,1,1,1};
        // int dc[]={-1,0,1,-1,1,-1,0,1};
        int dr[]={-1,0,0,1};
        int dc[]={0,1,-1,0};
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        for(int i=0;i<4;i++){
                            if(r+dr[i]>=0 && r+dr[i]<m && c+dc[i]>=0 && c+dc[i]<n && grid[r+dr[i]][c+dc[i]]=='1'){
                                grid[r+dr[i]][c+dc[i]]='0';
                                q.push({r+dr[i],c+dc[i]});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};