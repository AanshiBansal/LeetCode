class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    count++;
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int time=0;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!q.empty() && count>0){
            time++;
            int size=q.size();
            for(int k=0;k<size;k++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int l=0;l<4;l++){
                    if(x+dx[l]>=0 && x+dx[l]<m && y+dy[l]>=0 && y+dy[l]<n && grid[x+dx[l]][y+dy[l]]==1){
                        grid[x+dx[l]][y+dy[l]]=2;
                        count--;
                        q.push({x+dx[l],y+dy[l]});
                    }
                }
            }
        }
        if(count==0)
            return time;
        return -1;
    }
};