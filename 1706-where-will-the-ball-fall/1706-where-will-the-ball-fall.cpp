typedef pair<int,int> pr;
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>ans(n,-1);
        queue<pr>q;
        for(int j=0;j<n;j++){
            if(grid[0][j]==1 && j+1!=n && grid[0][j+1]==1){
                q.push({j+1,j});
            }
            if(grid[0][j]==-1 && j-1!=-1 && grid[0][j-1]==-1){
                q.push({j-1,j});
            }
        }
        int row=0;
        while(row+1<m && q.size()>0){
            int size=q.size();
            for(int x=0;x<size;x++){
                int col=q.front().first;
                int ball=q.front().second;
                q.pop();
                if(grid[row][col]==1){
                    if(grid[row+1][col]==1 && col+1!=n && grid[row+1][col+1]==1)
                        q.push({col+1,ball});
                    if(grid[row+1][col]==-1 && col-1!=-1 && grid[row+1][col-1]==-1)
                        q.push({col-1,ball});
                }
                if(grid[row][col]==-1){
                    if(grid[row+1][col]==-1 && col-1!=-1 && grid[row+1][col-1]==-1)
                        q.push({col-1,ball});
                    if(grid[row+1][col]==1 && col+1!=n && grid[row+1][col+1]==1)
                        q.push({col+1,ball});
                }
            }
            row++;
        }
        while(!q.empty()){
            int col=q.front().first;
            int ball=q.front().second;
            q.pop();
            ans[ball]=col;
        }
        return ans;
    }
};