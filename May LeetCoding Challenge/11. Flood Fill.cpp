//BFS of Graph

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        if(m==0)
            return image;
        int n=image[0].size();
        int color=image[sr][sc];
        if(color==newColor)
            return image;
        queue<pair<int,int> >q;
        q.push({sr,sc});
        image[sr][sc]=newColor;
        while(!q.empty()){
            pair<int,int>coord=q.front();
            q.pop();
            if(coord.first-1>=0 && image[coord.first-1][coord.second]==color)
            {   
                image[coord.first-1][coord.second]=newColor;
                q.push({coord.first-1,coord.second});
            }
            if(coord.first+1<m && image[coord.first+1][coord.second]==color)
            {
                image[coord.first+1][coord.second]=newColor;
                q.push({coord.first+1,coord.second});
            }  
            if(coord.second-1>=0 && image[coord.first][coord.second-1]==color)
            {
                image[coord.first][coord.second-1]=newColor;
                q.push({coord.first,coord.second-1});
            }
            if(coord.second+1<n && image[coord.first][coord.second+1]==color)
            {
                image[coord.first][coord.second+1]=newColor;
                q.push({coord.first,coord.second+1});
            }
        }
        return image;
    }
};
