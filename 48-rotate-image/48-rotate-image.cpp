class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int top=0,left=0,right=n-1,bottom=n-1;
        while(top<bottom){
            int size=bottom-top;
            for(int i=0;i<size;i++){
                int holder=matrix[top][left+i];
                matrix[top][left+i]=matrix[bottom-i][left];
                matrix[bottom-i][left]=matrix[bottom][right-i];
                matrix[bottom][right-i]=matrix[top+i][right];
                matrix[top+i][right]=holder;
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        return;
    }
};