//Priority Queue

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, pair<int,int> > > pq; 
        for(int i=0;i<points.size();i++){
            pq.push({-1*(points[i][0]*points[i][0]+points[i][1]*points[i][1]),{points[i][0],points[i][1]}});
        }
        vector<vector<int> >ans(K,vector<int>(2));
        for(int i=0;i<K;i++){
            ans[i][0]=pq.top().second.first;
            ans[i][1]=pq.top().second.second;
            pq.pop();
        }
        return ans;
    }
};
