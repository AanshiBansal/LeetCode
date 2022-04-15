class Solution {
public:
    // int minMeetingRooms(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(),intervals.end());
    //     int ans=0;
    //     priority_queue<int,vector<int>,greater<int>>pq;
    //     for(int i=0;i<intervals.size();i++){
    //         while(!pq.empty() && pq.top()<=intervals[i][0]){
    //             pq.pop();
    //         }
    //         pq.push(intervals[i][1]);
    //         int size=pq.size();
    //         ans=max(ans,size);
    //     }
    //     return ans;
    // }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int>count(1000001,0);
        for(int i=0;i<intervals.size();i++){
            count[intervals[i][0]]++;
            count[intervals[i][1]]--;
        }
        int ans=count[0];
        for(int i=1;i<=1000000;i++){
            count[i]+=count[i-1];
            ans=max(ans,count[i]);
        }
        return ans;
    }
};