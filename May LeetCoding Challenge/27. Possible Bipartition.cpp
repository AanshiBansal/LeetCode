// BFS- Graph Colouring using 2 colors
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int> >adj(N+1,vector<int>());
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int>colour(N+1,-1);
        for(int i=1;i<=N;i++){
            if(colour[i]==-1){
                colour[i]=0;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int top=q.front();
                    q.pop();
                    for(int j:adj[top]){
                        if(colour[j]==-1){
                            colour[j]=(colour[top]==0)?1:0;
                            q.push(j);
                        }
                        else{
                            if(colour[j]==colour[top])
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
