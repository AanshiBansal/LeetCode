class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n=intervals.size();
        if(n==0)
            return ans;
        sort(intervals.begin(),intervals.end());
        vector<int>curr=intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=curr[1]){
                curr[1]=max(intervals[i][1],curr[1]);
            }else{
                ans.push_back(curr);
                curr=intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};