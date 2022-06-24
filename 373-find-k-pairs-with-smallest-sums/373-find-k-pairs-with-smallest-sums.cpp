typedef pair<int,pair<int,int>> pr;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        priority_queue<pr,vector<pr>,greater<pr>>pq;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<m;i++){
            pq.push({nums1[0]+nums2[i],{0,i}});
        }
        int count=0;
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            count++;
            ans.push_back({nums1[r],nums2[c]});
            if(count==k)
                return ans;
            if(r+1<n){
                pq.push({nums1[r+1]+nums2[c],{r+1,c}});
            }
        }
        return ans;
    }
};