class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size())
            return false;
        unordered_set<int>set;
        int curr=0;
        for(int i=0;i<k;i++){
            curr*=2;
            if(s[i]=='1')
                curr+=1;
        }
        set.insert(curr);
        int mask=(~(1<<(k-1)));
        for(int i=k;i<s.size();i++){
            curr&=mask;
            curr*=2;
            if(s[i]=='1')
                curr+=1;
            set.insert(curr);
        }
        return set.size()==pow(2,k);
    }
};