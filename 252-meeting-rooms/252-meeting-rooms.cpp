class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int end=-1;
        for(int i=0;i<intervals.size();i++){
            if(end>intervals[i][0])
                return false;
            end=intervals[i][1];
        }
        return true;
    }
};