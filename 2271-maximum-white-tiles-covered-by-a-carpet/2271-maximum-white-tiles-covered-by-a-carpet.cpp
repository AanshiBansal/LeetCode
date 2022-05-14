class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int n=tiles.size();
        int ans=0;
        int curr=0;
        int end=0;
        for(int i=0;i<n;i++){
            if(i>0){
                curr-=(tiles[i-1][1]-tiles[i-1][0]+1);
            }
            int temp=curr;
            while(end<n && tiles[end][0]-tiles[i][0]<=carpetLen){
                int l=(tiles[end][1]-tiles[i][0]+1);
                if(l<=carpetLen){
                    curr+=(tiles[end][1]-tiles[end][0]+1);
                    temp=curr;
                    end++;
                }else{
                    temp+=(carpetLen-(tiles[end][0]-tiles[i][0]));
                    break;
                }
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};