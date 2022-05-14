class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        if(s.size()<k)
            return 0;
        int ans=0;
        int curr=0;
        for(int i=0;i<k;i++){
            curr*=10;
            curr+=(s[i]-'0');
        }
        int mod=pow(10,k-1);
        if(curr!=0 && num%curr==0)
            ans++;
        for(int i=k;i<s.size();i++){
            curr%=mod;
            curr*=10;
            curr+=(s[i]-'0');
            if(curr!=0 && num%curr==0)
                ans++;
        }
        return ans;
    }
};