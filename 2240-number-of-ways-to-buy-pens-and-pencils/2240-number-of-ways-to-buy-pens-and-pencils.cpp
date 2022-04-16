class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
        long long maxp=total/cost1;
        for(int i=0;i<=maxp;i++){
            int c=total-(cost1*i);
            ans+=c/cost2 + 1;
        }
        return ans;
    }
};