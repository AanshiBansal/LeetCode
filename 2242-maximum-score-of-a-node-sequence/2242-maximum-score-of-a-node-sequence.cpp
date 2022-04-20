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
        int n = scores.size();
        vector<priority_queue<pr,vector<pr>,greater<pr>>>adj(n);
        int ans=-1;
        for(auto edge:edges){
            int n1=edge[0];
            int n2=edge[1];
            adj[n1].push({scores[n2], n2});
            if(adj[n1].size()>3)
                adj[n1].pop();
            adj[n2].push({scores[n1], n1});
            if(adj[n2].size()>3)
                adj[n2].pop();
        }
        vector<vector<int>>neighbors(n);
        for(int i=0;i<n;i++){
            while(!adj[i].empty()){
                neighbors[i].push_back(adj[i].top().second);
                adj[i].pop();
            }
        }
        for(auto edge:edges){
            int n1=edge[0];
            int n2=edge[1];
            for(int neighbor1: neighbors[n1]){
                for(int neighbor2: neighbors[n2]){
                    if(neighbor1 != n2 && neighbor1!=neighbor2 && neighbor2!= n1){
                        ans=max(ans,scores[n1]+scores[n2]+scores[neighbor1]+scores[neighbor2]);
                    }
                }
            }
        }
        return ans;
    }
};