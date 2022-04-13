class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>sol(numRows);
        vector<int>curr;
        for(int i=1;i<=numRows;i++){
            curr.push_back(1);
            for(int j=1;j<i-1;j++){
                curr[j]=sol[i-1-1][j-1]+sol[i-1-1][j];
            }
            sol[i-1]=curr;
        }
        return sol;
    }
};