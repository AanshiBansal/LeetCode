class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)
            return 0;
        long Path[obstacleGrid.size()][obstacleGrid[0].size()];
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        Path[0][0]=1;
        for(int i=1;i<n;i++)
            if(obstacleGrid[0][i]==1)
            Path[0][i]=0;
        else
            Path[0][i]=Path[0][i-1];
        for(int i=1;i<m;i++)
        if(obstacleGrid[i][0]==1)
            Path[i][0]=0;
        else
            Path[i][0]=Path[i-1][0];
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1)
                    Path[i][j]=0;
                else
               Path[i][j]=Path[i-1][j]+Path[i][j-1];
            }
        return Path[m-1][n-1];
        
    }
};