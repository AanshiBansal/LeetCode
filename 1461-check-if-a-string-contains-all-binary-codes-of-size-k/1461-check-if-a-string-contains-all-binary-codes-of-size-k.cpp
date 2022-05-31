class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int>set;
        int curr=0;
        int mask=(~(1<<(k-1)));
        for(int i=0;i<s.size();i++){
            curr&=mask;
            curr*=2;
            if(s[i]=='1')
                curr+=1;
            if(i>=k-1)
                set.insert(curr);
        }
        return set.size()==pow(2,k);
    }
};