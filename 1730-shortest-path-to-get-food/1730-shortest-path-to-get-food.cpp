typedef pair<int,pair<int,int> > pr;
class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pr>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='*'){
                    q.push({0,{i,j}});
                    break;
                }
            }
        }
        while(!q.empty()){
            pr top=q.front();
            q.pop();
            int dist=top.first;
            int i=top.second.first;
            int j=top.second.second;
            if(i-1>=0 && grid[i-1][j]=='#')
                return dist+1;
            if(i+1<m && grid[i+1][j]=='#')
                return dist+1;
            if(j-1>=0 && grid[i][j-1]=='#')
                return dist+1;
            if(j+1<n && grid[i][j+1]=='#')
                return dist+1;
            
            if(i-1>=0 && grid[i-1][j]=='O'){
                grid[i-1][j]='X';
                q.push({dist+1,{i-1,j}});
            }
            if(i+1<m && grid[i+1][j]=='O'){
                grid[i+1][j]='X';
                q.push({dist+1,{i+1,j}});
            }
            if(j-1>=0 && grid[i][j-1]=='O'){
                grid[i][j-1]='X';
                q.push({dist+1,{i,j-1}});
            }
            if(j+1<n && grid[i][j+1]=='O'){
                grid[i][j+1]='X';
                q.push({dist+1,{i,j+1}});
            }
        }
        return -1;
    }
};