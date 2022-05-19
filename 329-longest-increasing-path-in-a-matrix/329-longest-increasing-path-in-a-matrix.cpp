class Solution {
private:
    int dfs(vector<vector<int>>&mp,vector<vector<int>>& matrix,int i, int j, int m, int n){
        if(mp[i][j]!=-1)
            return mp[i][j];
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        int next=0;
        for(int k=0;k<4;k++){
            int a=i+dx[k];
            int b=j+dy[k];
            if(a>=0 && a<m && b>=0 && b<n && matrix[a][b]>matrix[i][j]){
                next=max(next,dfs(mp,matrix,a,b,m,n));
            }
        }
        mp[i][j]=next+1;
        return mp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>mp(m,vector<int>(n,-1));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dfs(mp,matrix,i,j,m,n));
            }
        }
        return ans;
    }
};