class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>dist(1001,0);
        for(int i=0;i<trips.size();i++){
            dist[trips[i][1]]+=trips[i][0];
            dist[trips[i][2]]-=trips[i][0];
        }
        int curr=0;
        for(int i=0;i<=1000;i++){
            curr+=dist[i];
            if(curr>capacity)
                return false;
        }
        return true;
    }
};