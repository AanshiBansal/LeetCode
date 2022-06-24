// typedef pair<int,pair<int,int>> pr;
// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         priority_queue<pr,vector<pr>,greater<pr>>pq;
//         int n=matrix.size();
//         for(int i=0;i<n;i++){
//             pq.push({matrix[0][i],{0,i}});
//         }
//         int count=0;
//         while(!pq.empty()){
//             int val=pq.top().first;
//             int r=pq.top().second.first;
//             int c=pq.top().second.second;
//             pq.pop();
//             count++;
//             if(count==k)
//                 return val;
//             if(r+1<n){
//                 pq.push({matrix[r+1][c],{r+1,c}});
//             }
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low<high){
            int mid=low+(high-low)/2;
            int count=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]<=mid)
                        count++;
                    else
                        break;
                }
            }
            if(count>=k){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};