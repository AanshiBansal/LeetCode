class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int> > >adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>ans(n+1,INT_MAX);
        ans[k]=0;
        priority_queue<pair<int,int>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int cost=-1*pq.top().first;
            //cout<<node<<" "<<cost<<" ";
            pq.pop();
            if(cost<=ans[node]){
                for(int i=0;i<adj[node].size();i++){
                    if(ans[adj[node][i].first]>adj[node][i].second+cost){
                        ans[adj[node][i].first]=adj[node][i].second+cost;
                        pq.push({-1*ans[adj[node][i].first],adj[node][i].first});
                    }
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++)
            maxi=max(maxi,ans[i]);
        return maxi==INT_MAX?-1:maxi;
    }
};