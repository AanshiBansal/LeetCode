class Solution {
public:
    string reverseWords(string A) {
        stack<string>s;
        string temp ="";
        for(int i=0;i<A.size();i++){
            if(A[i]==' '){
                if(temp!="")
                s.push(temp);
                temp="";
            }
            else{
                temp+=A[i];
            }
        }
        if(temp!="")
            s.push(temp);
        string ans="";
        while(!s.empty()){
            ans+=s.top();
            s.pop();
            if(!s.empty())
                ans+=" ";
        }
        return ans;
    }
};