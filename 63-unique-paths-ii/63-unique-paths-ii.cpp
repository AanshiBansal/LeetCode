class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)
            return 0;
        vector<vector<int>>pathCount(m, vector<int>(n));
        pathCount[0][0]=1;
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i]==1)
                pathCount[0][i]=0;
            else
                pathCount[0][i]=pathCount[0][i-1];
        }
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]==1)
                pathCount[i][0]=0;
            else
                pathCount[i][0]=pathCount[i-1][0];
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1)
                    pathCount[i][j]=0;
                else
                    pathCount[i][j]=pathCount[i-1][j]+pathCount[i][j-1];
            }
        return pathCount[m-1][n-1];
    }
};