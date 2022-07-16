bool fn(pair<int,int>&a, pair<int,int>&b){
    return a.second>b.second || (a.second==b.second && a.first<b.first);
} 
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int sum=0;
        int maxi=0;
        int n=plantTime.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={plantTime[i],growTime[i]};
        }
        sort(v.begin(),v.end(),fn);
        for(int i=0;i<n;i++){
            sum+=v[i].first;
            maxi=max(v[i].second,maxi-v[i].first);
        }
        return sum+maxi;
    }
};