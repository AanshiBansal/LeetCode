class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>=2){
            sort(s.begin(),s.end());
            return s;
        }
        int n=s.size();
        string ans=s;
        s+=s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i+j]>ans[j])
                    break;
                if(s[i+j]<ans[j]){
                    ans=s.substr(i,n);
                    break;
                }
            }
        }
        return ans;
    }
};