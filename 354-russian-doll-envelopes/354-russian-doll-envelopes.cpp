// class Solution {
// private:
//     int dfs(vector<vector<int>>& adj, vector<int>&depth, int node){
//         if(depth[node]!=0)
//             return depth[node];
//         int ans=0;
//         for(int neighbor:adj[node]){
//             ans=max(ans,dfs(adj,depth,neighbor));
//         }
//         return depth[node]=ans+1;
//     }
// public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         int n=envelopes.size();
//         vector<vector<int>>adj(n);
//         sort(envelopes.begin(),envelopes.end());
//         for(int i=n-1;i>=0;i--){
//             for(int j=i-1;j>=0;j--){
//                 if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1])
//                     adj[i].push_back(j);
//             }
//         }
//         vector<int>depth(n,0);
//         int ans=0;
//         for(int i=0;i<n;i++){
//             ans=max(ans,dfs(adj,depth,i));
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         int n=envelopes.size();
//         vector<vector<int>>adj(n);
//         vector<int>inbound(n,0);
//         sort(envelopes.begin(),envelopes.end());
//         for(int i=n-1;i>=0;i--){
//             for(int j=i-1;j>=0;j--){
//                 if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
//                     adj[j].push_back(i);
//                     inbound[i]++;
//                 }
//             }
//         }
//         queue<int>q;
//         for(int i=0;i<n;i++){
//             if(inbound[i]==0){
//                 q.push(i);
//             }
//         }
//         int ans=0;
//         while(!q.empty()){
//             ans++;
//             int size=q.size();
//             for(int i=0;i<size;i++){
//                 int node=q.front();
//                 q.pop();
//                 for(int neighbor:adj[node]){
//                     inbound[neighbor]--;
//                     if(inbound[neighbor]==0)
//                         q.push(neighbor);
//                 }
//             }
//         }
//         return ans;
//     }
// };

bool comp(vector<int>&a, vector<int>&b){
    if(a[0]<b[0])
        return true;
    if(a[0]==b[0] && a[1]>b[1])
        return true;
    return false;
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),comp);
        vector<int>ans;
        for(int i=0;i<envelopes.size();i++){
            int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
            if(index==ans.size())
                ans.push_back(envelopes[i][1]);
            else
                ans[index]=envelopes[i][1];
        }
        return ans.size();
    }
};