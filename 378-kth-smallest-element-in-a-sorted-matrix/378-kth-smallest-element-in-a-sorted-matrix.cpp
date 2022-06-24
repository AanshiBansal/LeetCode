typedef pair<int,pair<int,int>> pr;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pr,vector<pr>,greater<pr>>pq;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            pq.push({matrix[0][i],{0,i}});
        }
        int count=0;
        while(!pq.empty()){
            int val=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            count++;
            if(count==k)
                return val;
            if(r+1<n){
                pq.push({matrix[r+1][c],{r+1,c}});
            }
        }
        return 0;
    }
};