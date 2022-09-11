class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={efficiency[i],speed[i]};
        }
        sort(v.begin(),v.end(),greater());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long totalSpeed=0,ans=0;
        for(int i=0;i<n;i++){
            pq.push(v[i].second);
            totalSpeed+=v[i].second;
            if(pq.size()>k){
                totalSpeed-=pq.top();
                pq.pop();
            }
            ans=max(ans,(totalSpeed*v[i].first));
        }
        return ans%1000000007;
    }
};