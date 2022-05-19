class Solution {
public:
    int largestVariance(string s) {
        int n=s.size();
        int ans=0;
        // for(int i=0;i<n;i++){
        //     vector<int>mp(26,0);
        //     for(int j=i;j<n;j++){
        //         mp[s[j]-'a']++;
        //         for(int k=0;k<26;k++){
        //             for(int l=k;l<26;l++){
        //                 if(mp[k]!=0 && mp[l]!=0)
        //                     ans=max(ans,abs(mp[l]-mp[k]));
        //             }
        //         }
        //     }
        // }
        vector<int>occurances(26,0);
        for(int i=0;i<n;i++){
            occurances[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j || occurances[i]==0 || occurances[j]==0)
                    continue;
                int ci=0;
                int cj=0;
                int left=occurances[i];
                for(int k=0;k<n;k++){
                    if(s[k]-'a'==i){
                        ci++;
                        left--;
                        if(ci>cj && left>0){
                            ci=0;
                            cj=0;
                        }
                    }
                    if(s[k]-'a'==j){
                        cj++;
                    }
                    if(ci>0)
                        ans=max(ans,cj-ci);
                }
            }
        }
        return ans;
    }
};