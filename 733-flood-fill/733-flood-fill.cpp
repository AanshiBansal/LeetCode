class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        int m=image.size();
        int n=image[0].size();
        // int dr[]={-1,-1,-1,0,0,1,1,1};
        // int dc[]={-1,0,1,-1,1,-1,0,1};
        int dr[]={-1,0,0,1};
        int dc[]={0,1,-1,0};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int source=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                if(r+dr[i]>=0 && r+dr[i]<m && c+dc[i]>=0 && c+dc[i]<n && image[r+dr[i]][c+dc[i]]==source){
                    image[r+dr[i]][c+dc[i]]=color;
                    q.push({r+dr[i],c+dc[i]});
                }
            }
        }
        return image;
    }
};