class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int,int>mp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(mp.find(i-j)==mp.end())
                    mp[i-j]=matrix[i][j];
                else
                    if(matrix[i][j]!=mp[i-j])
                        return false;
            }
        }
        return true;
    }
};