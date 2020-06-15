//Graph BFS 
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    if(src==dst)
        return 0;
    vector<vector<pair<int,int> > >adj(n,vector<pair<int,int> >());
    for(int i=0;i<flights.size();i++)
        adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
    int ans=INT_MAX;
    queue<vector<int> >q;
    q.push({src,0,0});
    while(!q.empty()){
        int city=q.front()[0];
        int cost=q.front()[1];
        int stops=q.front()[2];
        q.pop();
        for(int i=0;i<adj[city].size();i++){
            if(adj[city][i].first==dst)
                ans=min(ans,cost+adj[city][i].second);
            else if(cost+adj[city][i].second<ans && stops+1 <=K)
            q.push({adj[city][i].first,cost+adj[city][i].second,stops+1});
        }
        
    }
    if(ans==INT_MAX)
        return -1;
    return ans;
}
