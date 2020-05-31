//Topological Sort

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int> >adj(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        int count=0;
        //int *ans = new int[V];
        vector<bool>vis(numCourses,false);
        while(count!=numCourses){
            int start=count;
            for(int i=0;i<numCourses;i++){
                if(indegree[i]==0 && vis[i]==false){
                    vis[i]=true;
                    count++;
                    for(auto x:adj[i])
                    indegree[x]--;
                }
            }
            if(count==start)
                return false;
        }
        return true;
    }
};
