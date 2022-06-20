class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<vector<int>>adj(n,vector<int>());
        vector<int>inbound(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            inbound[edges[i][0]]++;
            adj[edges[i][1]].push_back(edges[i][0]);
            inbound[edges[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inbound[i]==1)
                q.push(i);
        }
        int total=n;
        while(total>2){
            int size=q.size();
            for(int i=0;i<size;i++){
                int front=q.front();
                q.pop();
                total--;
                for(int neighbor:adj[front]){
                    inbound[neighbor]--;
                    if(inbound[neighbor]==1)
                        q.push(neighbor);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};