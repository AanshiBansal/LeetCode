class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool rTop=false;
        vector<int>ans;
        int m=mat.size();
        int n=mat[0].size();
        for(int d=0;d<=m+n-2;d++){
            if(rTop){
                for(int i=0;i<m;i++){
                    int j=d-i;
                    if(j>=0 && j<n)
                        ans.push_back(mat[i][j]);
                }
            }else{
                for(int i=m-1;i>=0;i--){
                    int j=d-i;
                    if(j>=0 && j<n)
                        ans.push_back(mat[i][j]);
                }
            }
            rTop=!rTop;
        }
        return ans;
    }
};