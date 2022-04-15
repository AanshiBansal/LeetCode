class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int select=damage[0];
        long long ans=damage[0];
        for(int i=1;i<damage.size();i++){
            select=max(select,damage[i]);
            ans+=damage[i];
        }
        select=min(select,armor);
        ans-=select;
        return ans+1;
    }
};