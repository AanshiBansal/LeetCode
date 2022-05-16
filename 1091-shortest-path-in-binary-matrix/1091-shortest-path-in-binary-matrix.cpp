typedef pair<int,pair<int,int>> pr;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)
            return -1;
        if(n==1)
            return 1;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        priority_queue< pr, vector<pr>, greater<pr> >pq;
        pq.push({1,{0,0}});
        vis[0][0]=true;
        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};
        while(!pq.empty()){
            int dist=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int k=0;k<8;k++){
                int a=x+dx[k];
                int b=y+dy[k];
                if(a>=0 && a<n && b>=0 && b<n && grid[a][b]==0 && vis[a][b]==false){
                    if(a==n-1 && b==n-1)
                        return dist+1;
                    vis[a][b]=true;
                    pq.push({dist+1,{a,b}});
                }
            }
        }
        return -1;
    }
};