class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int num:arr){
            mp[num]++;
        }
        priority_queue<int>pq;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            pq.push(itr->second);
        }
        int ans=0;
        int count=0;
        while(count<arr.size()/2){
            ans++;
            count+=pq.top();
            pq.pop();
        }
        return ans;
    }
};