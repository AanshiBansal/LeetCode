// class Solution {
// public:
//     int maxProduct(vector<string>& words) {
//         int n=words.size();
//         vector<vector<bool>>count(n,vector<bool>(26,0));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<words[i].size();j++){
//                 count[i][words[i][j]-'a']=true;
//             }
//         }
//         unsigned long ans=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 bool flag=true;
//                 for(int k=0;k<26;k++){
//                     if(count[i][k] && count[j][k]){
//                         flag=false;
//                         break;
//                     }
//                 }
//                 if(flag){
//                     ans=max(ans,words[i].size()*words[j].size());
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>bitValue(n);
        for(int i=0;i<n;i++){
            int value=0;
            for(int j=0;j<words[i].size();j++){
                value|=(1<<(words[i][j]-'a'));
            }
            bitValue[i]=value;
        }
        unsigned long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!((bitValue[i]&bitValue[j])>0)){
                    ans=max(ans,words[i].size()*words[j].size());
                }
            }
        }
        return ans;
    }
};