class Solution {
public:
    char opposite(char c){
        if(c>='A' && c<='Z')
            return c-'A'+'a';
        return c-'a'+'A';
    }
    string makeGood(string s) {
        deque<char>dq;
        for(char c:s){
            if(!dq.empty() && dq.back()==opposite(c))
                dq.pop_back();
            else
                dq.push_back(c);
        }
        string ans="";
        while(!dq.empty()){
            ans+=dq.front();
            dq.pop_front();
        }
        return ans;
    }
};