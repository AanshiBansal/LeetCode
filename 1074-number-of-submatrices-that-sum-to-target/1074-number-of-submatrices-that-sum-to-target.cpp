/*class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int j=1;j<n;j++)
            matrix[0][j]+=matrix[0][j-1];
        for(int i=1;i<m;i++)
            matrix[i][0]+=matrix[i-1][0];
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                matrix[i][j]+=(matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1]);
        
        int ans=0;
        for(int r1=0;r1<m;r1++){
            for(int r2=r1;r2<m;r2++){
                for(int c1=0;c1<n;c1++){
                    for(int c2=c1;c2<n;c2++){
                        int curr=matrix[r2][c2];
                        if(r1-1>=0)
                            curr-=matrix[r1-1][c2];
                        if(c1-1>=0)
                            curr-=matrix[r2][c1-1];
                        if(r1-1>=0 && c1-1>=0)
                            curr+=matrix[r1-1][c1-1];
                        if(curr==target)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int res = 0, m = A.size(), n = A[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                A[i][j] += A[i][j - 1];

        unordered_map<int, int> counter;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                counter = {{0,1}};
                int cur = 0;
                for (int k = 0; k < m; k++) {
                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
                    res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
                    counter[cur]++;
                }
            }
        }
        return res;
    }
};