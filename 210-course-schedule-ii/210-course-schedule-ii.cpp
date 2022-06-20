class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses,vector<int>());
        vector<int>inbound(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inbound[prerequisites[i][0]]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(inbound[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty() && ans.size()<numCourses){
            int curr=q.front();
            q.pop();
            for(int neighbor:adj[curr]){
                inbound[neighbor]--;
                if(inbound[neighbor]==0){
                    q.push(neighbor);
                    ans.push_back(neighbor);
                }
            }
        }
        if(ans.size()==numCourses)
            return ans;
        return {};
    }
};