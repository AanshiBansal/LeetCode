class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>v;
        auto it=v.end();
        for(int num:nums){
            it=lower_bound(v.begin(),v.end(),num);
            if(it==v.end())
                v.push_back(num);
            else
                *it=num;
            if(v.size()==3)
                return true;
        }
        return false;
    }
};