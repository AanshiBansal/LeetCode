//dp
int minPathSum(vector<vector<int>>& cost) {
    int m= cost.size();
    int n=cost[0].size();
    for(int j=1;j<n;j++)
        cost[0][j]=cost[0][j-1]+cost[0][j];
    for(int i=1;i<m;i++)
        cost[i][0]=cost[i-1][0]+cost[i][0];
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            cost[i][j]= min(cost[i-1][j],cost[i][j-1])+cost[i][j];
    return cost[m-1][n-1];
}
