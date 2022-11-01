typedef pair<int,int> pr;
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>ans(n);
        for(int j=0;j<n;j++)
            ans[j]=j;
        for(int row=-1;row<m-1;row++){
            for(int ball=0;ball<n;ball++){
                if(ans[ball]==-1)
                    continue;
                int col=ans[ball];
                if(grid[row+1][col]==1 && col+1!=n && grid[row+1][col+1]==1)
                    ans[ball]=col+1;
                else if(grid[row+1][col]==-1 && col-1!=-1 && grid[row+1][col-1]==-1)
                    ans[ball]=col-1;
                else
                    ans[ball]=-1;
            }
        }
        return ans;
    }
};