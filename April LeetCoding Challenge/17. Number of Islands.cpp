//4 dimension BFS
int numIslands(vector<vector<char>>& A) {
    int ans=0;
    int m=A.size();
    if(m==0)
        return 0;
    int n=A[0].size();
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(A[i][j]=='1'){
                ans++;
                queue<pair<int,int> >q;
                q.push({i,j});
                A[i][j]='0';
                while(!q.empty()){
                    pair<int,int>top=q.front();
                    q.pop();
                    int x=top.first;
                    int y=top.second;
                    for(int k=0;k<4;k++)
                        if(x+dx[k]>=0 && x+dx[k]<m && y+dy[k]>=0 && y+dy[k]<n && A[x+dx[k]][y+dy[k]]=='1'){
                            q.push({x+dx[k],y+dy[k]});
                            A[x+dx[k]][y+dy[k]]='0';
                    }
                }
            }
 	return ans;   
}
