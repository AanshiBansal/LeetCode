class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int n=tiles.size();
        int prev=0;
        int carpetStart=tiles[0][0];
        int ans=0;
        int l=0;
        int curr=0;
        int prevEnding=tiles[0][0]-1;
        for(int i=0;i<n;i++){
            curr+=(tiles[i][1]-tiles[i][0]+1);
            l+=(tiles[i][1]-prevEnding);
            prevEnding=tiles[i][1];
            while(l>carpetLen){
                //cout<<"here"<<i<<endl;
                l--;
                if(carpetStart<=tiles[prev][1]);
                else
                    prev++;
                if(carpetStart>=tiles[prev][0]){
                    //cout<<"here"<<i<<" "<<carpetStart<<" "<<prev<<endl;
                    curr--;
                }
                carpetStart++;
            }
            ans=max(ans,curr);
            //cout<<i<<" "<<curr<<" "<<ans<<endl;
        }
        return ans;
    }
};