//Stack

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        int i=0;
        while(k && i<num.size()){
            while(!s.empty()&&s.top()>num[i]&&k>0){
                s.pop();
                k--;
            }
            s.push(num[i]);
            i++;
        }
        while(k){
            s.pop();
            k--;
        }
        string ans="";
        for(int j=num.size()-1;j>=i;j--){
            ans=num[j]+ans;
        }
        while(!s.empty()){
            ans=s.top()+ans;
            s.pop();
        }
        i=0;
        for(;i<ans.size();i++){
            if(ans[i]!='0')
                break;
        }
        ans=ans.substr(i);
        if(ans=="")
            ans="0";
        return ans;
    }
};
