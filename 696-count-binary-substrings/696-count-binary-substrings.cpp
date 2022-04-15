class Solution {
public:
    // int countBinarySubstrings(string s) {
    //     int n=s.size();
    //     vector<int>zeros(n,0);
    //     vector<int>ones(n,0);
    //     if(s[n-1]=='1')
    //         ones[n-1]=1;
    //     else
    //         zeros[n-1]=1;
    //     for(int i=n-2;i>=0;i--){
    //         if(s[i]=='0')
    //             zeros[i]=zeros[i+1]+1;
    //         else
    //             ones[i]=ones[i+1]+1;
    //     }
    //     int zero=0;
    //     int one=0;
    //     int ans=0;
    //     for(int i=0;i<n-1;i++){
    //         if(s[i]=='0'){
    //             zero++;
    //             one=0;
    //         }else{
    //             zero=0;
    //             one++;
    //         }
    //         ans+=min(zero,ones[i+1])+min(one,zeros[i+1]);
    //     }
    //     return ans;
    // }
    int countBinarySubstrings(string s) {
        int n=s.size();
        int ans=0;
        int curr=1;
        int prev=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                curr++;
            }else{
                ans+=min(prev,curr);
                prev=curr;
                curr=1;
            }
        }
        return ans+min(prev,curr);
    }
};