// class Solution {
// public:
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//         vector<int>dist(1001,0);
//         for(int i=0;i<trips.size();i++){
//             dist[trips[i][1]]+=trips[i][0];
//             dist[trips[i][2]]-=trips[i][0];
//         }
//         int curr=0;
//         for(int i=0;i<=1000;i++){
//             curr+=dist[i];
//             if(curr>capacity)
//                 return false;
//         }
//         return true;
//     }
// };

// class Solution {
// public:
//     bool carPooling(vector<vector<int>>& trips, int capacity) {
//         map<int,int>mp;
//         for(int i=0;i<trips.size();i++){
//             mp[trips[i][1]]+=trips[i][0];
//             mp[trips[i][2]]-=trips[i][0];
//         }
//         int curr=0;
//         for(auto p:mp){
//             curr+=p.second;
//             if(curr>capacity)
//                 return false;
//         }
//         return true;
//     }
// };

bool comp(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}
typedef pair<int,int> pr;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),comp);
        int curr=0;
        priority_queue<pr,vector<pr>,greater<pr>>pq;
        for(int i=0;i<trips.size();i++){
            curr+=trips[i][0];
            pq.push({trips[i][2],trips[i][0]});
            while(!pq.empty() && pq.top().first<=trips[i][1]){
                curr-=pq.top().second;
                pq.pop();
            }
            if(curr>capacity)
                return false;
        }
        return true;
    }
};