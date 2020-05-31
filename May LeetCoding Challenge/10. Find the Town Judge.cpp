class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<bool> >adj(N+1, vector<bool>(N+1,false));
        for(int i=0;i<trust.size();i++){
            adj[trust[i][0]][trust[i][1]]=true;
        }
        for(int i=1;i<=N;i++){
            bool pos=true;
            for(int j=1;j<=N;j++)
            if(adj[i][j]==true)
            { 
                pos=false;
                break;
            }
            if(pos){
                for(int j=1;j<=N;j++){
                    if(i!=j && adj[j][i]==false){
                        pos=false;
                        break;
                    }
                }
            }
            if(pos)
                return i;
                
        }
        return -1;
    }
};
