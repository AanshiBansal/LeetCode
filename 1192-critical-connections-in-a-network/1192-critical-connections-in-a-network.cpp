class Solution {
private:
    void dfs(vector<vector<int>>& adj, vector<bool>&vis, vector<int>&low, vector<int>&tin, int node, int parent, vector<vector<int>>&bridges, int &time){
        vis[node]=true;
        low[node]=time;
        tin[node]=time;
        time++;
        for(int neighbor:adj[node]){
            if(neighbor==parent)
                continue;
            if(vis[neighbor]==false){
                dfs(adj,vis,low,tin,neighbor,node,bridges,time);
                if(low[neighbor]>tin[node])
                    bridges.push_back({node,neighbor});
            }
            low[node]=min(low[node],low[neighbor]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>bridges;
        vector<vector<int>>adj(n,vector<int>());
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool>vis(n,false);
        vector<int>low(n,INT_MAX);
        vector<int>tin(n);
        int time=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(adj,vis,low,tin,i,-1,bridges,time);
            }
        }
        return bridges;
    }
};