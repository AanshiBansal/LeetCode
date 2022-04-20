// class Solution {
// private:
//     vector<int>scores;
//     vector<vector<int>>adj;
//     void dfs(vector<bool>&vis,int node, int &ans,int count,int curr){
//         if(count==3){
//             ans=max(ans,curr+scores[node]);
//             return;
//         }
//         vis[node]=true;
//         for(int neighbor:adj[node]){
//             if(vis[neighbor]==false){
//                 dfs(vis,neighbor,ans,count+1,curr+scores[node]);
//             }
//         }
//         vis[node]=false;
//     }
// public:
//     int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
//         this->scores=scores;
//         int n=scores.size();
//         adj = vector<vector<int>>(n);
//         for(auto edge:edges){
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }
//         int ans=-1;
//         vector<bool>vis(n,false);
//         for(int i=0;i<n;i++){
//             dfs(vis,i,ans,0,0);
//         }
//         return ans;
//     }
// };
typedef pair<int,int> pr;
class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        vector<priority_queue<pr,vector<pr>,greater<pr>>>adj(scores.size());
        int ans=-1;
        for(auto edge:edges){
            adj[edge[0]].push({scores[edge[1]], edge[1]});
            if(adj[edge[0]].size()>3)
                adj[edge[0]].pop();
            adj[edge[1]].push({scores[edge[0]], edge[0]});
            if(adj[edge[1]].size()>3)
                adj[edge[1]].pop();
        }
        int n = scores.size();
        vector<vector<int>>adj2(n);
        for(int i=0;i<n;i++){
            while(!adj[i].empty()){
                adj2[i].push_back(adj[i].top().second);
                adj[i].pop();
            }
        }
        for(auto edge:edges){
            int n1=edge[0];
            int n2=edge[1];
            for(auto nodes1: adj2[n1]){
                for(auto nodes2: adj2[n2]){
                    if(nodes1 != n2 && nodes1!=nodes2 && nodes2!= n1){
                        ans=max(ans,scores[n1]+scores[n2]+scores[nodes1]+scores[nodes2]);
                    }
                }
            }
        }
        return ans;
    }
};