//BFS
//Starting from outside keep marking regions that would be 'O' in result
void solve(vector<vector<char>>& A) {
    int m=A.size();
    if(m==0)
    return;
    int n=A[0].size();
    queue<pair<int,int> >q;
    for(int i=0;i<m;i++){
        if(A[i][0]=='O')
        {
            q.push({i,0});
            A[i][0]='Y';
        }
        if(A[i][n-1]=='O')
        {
            q.push({i,n-1});
            A[i][n-1]='Y';
        }
    }
    for(int j=1;j<n-1;j++){
        if(A[0][j]=='O')
        {
            q.push({0,j});
            A[0][j]='Y';
        }
        if(A[m-1][j]=='O')
        {
            q.push({m-1,j});
            A[m-1][j]='Y';
        }
    }
    while(!q.empty()){
        pair<int,int>front=q.front();
        q.pop();
        int i=front.first;
        int j=front.second;
        if(i-1>=0 && A[i-1][j]=='O')
        {q.push({i-1,j});A[i-1][j]='Y';}
        if(i+1<m && A[i+1][j]=='O')
        {q.push({i+1,j});A[i+1][j]='Y';}
        if(j+1<n && A[i][j+1]=='O')
        {q.push({i,j+1});A[i][j+1]='Y';}
        if(j-1>=0 && A[i][j-1]=='O')
        {q.push({i,j-1});A[i][j-1]='Y';}
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(A[i][j]=='Y')
                A[i][j]='O';
            else
                A[i][j]='X';
    return;
}
