// class Solution {
// public:
//     int minFlipsMonoIncr(string s) {
//         int n=s.size();
//         if(n==0)
//             return 0;
//         vector<int>one(n+1);
//         one[n]=0;
//         if(s[n-1]=='1'){
//             one[n-1]=0;
//         }else{
//             one[n-1]=1;
//         }
//         for(int i=n-2;i>=0;i--){
//             if(s[i]=='1'){
//                 one[i]=one[i+1];
//             }else{
//                 one[i]=one[i+1]+1;
//             }
//         }
//         int ans=one[0];
//         int zero=0;
//         for(int i=0;i<n;i++){
//             if(s[i]=='1')
//                 zero++;
//             ans=min(zero+one[i+1],ans);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int ones=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ones++;
            }else{
                ans=min(ans+1,ones);
            }
        }
        return ans;
    }
};