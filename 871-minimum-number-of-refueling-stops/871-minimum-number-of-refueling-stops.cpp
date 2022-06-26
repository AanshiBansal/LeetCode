class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target,0});
        priority_queue<int>pq;
        int ans=0;
        for(int i=0;i<stations.size();i++){
            while(!pq.empty() && startFuel-stations[i][0]<0){
                startFuel+=pq.top();
                pq.pop();
                ans++;
            }
            if(startFuel-stations[i][0]<0)
                return -1;
            pq.push(stations[i][1]);
        }
        return ans;
    }
};