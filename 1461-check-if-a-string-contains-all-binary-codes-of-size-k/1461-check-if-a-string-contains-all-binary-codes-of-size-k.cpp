class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int>set;
        int curr=0;
        for(int i=0;i<s.size();i++){
            if(i<k){
                curr*=2;
                if(s[i]=='1')
                    curr+=1;
            }else{
                curr&=(~(1<<(k-1)));
                curr*=2;
                if(s[i]=='1')
                    curr+=1;
            }
            if(i>=k-1){
                set.insert(curr);
            }
        }
        return set.size()==pow(2,k);
    }
};