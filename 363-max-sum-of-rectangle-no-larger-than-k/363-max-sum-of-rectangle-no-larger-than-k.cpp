class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        for (int row = 0; row < matrix.size(); ++row) {
            int currSum = 0;
            for (int col = 0; col < matrix[row].size(); ++col) {
                currSum += matrix[row][col];
                matrix[row][col] = currSum;
            }
        }
        
        int maxSum = INT_MIN;
        for (int lCol = 0; lCol < matrix[0].size(); ++lCol) {
            for (int rCol = lCol; rCol < matrix[0].size(); ++rCol) {
                
                set<int> bst; // RB tree
                bst.insert(0);
                
                int rowPrefSum = 0;
                for (int row = 0; row < matrix.size(); ++row) {
                    int currSum = matrix[row][rCol] - (lCol == 0 ? 0 : matrix[row][lCol-1]);
                    rowPrefSum += currSum;
                    
                    auto searchRes = bst.lower_bound(rowPrefSum - k);
                    
                    if (searchRes != bst.end()) {      
                        maxSum = max(maxSum, rowPrefSum - *searchRes);
                    }
                    
                    bst.insert(rowPrefSum);
                }
                
                
            }
        }
        
        return maxSum;
    }
};