class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses,vector<int>());
        vector<int>inbound(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inbound[prerequisites[i][0]]++;
        }
        queue<int>q;
        int count=numCourses;
        for(int i=0;i<numCourses;i++){
            if(inbound[i]==0){
                q.push(i);
                count--;
            }
        }
        while(!q.empty() && count>0){
            int curr=q.front();
            q.pop();
            for(int neighbor:adj[curr]){
                inbound[neighbor]--;
                if(inbound[neighbor]==0){
                    q.push(neighbor);
                    count--;
                }
            }
        }
        return count==0;
    }
};