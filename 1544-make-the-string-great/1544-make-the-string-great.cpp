class Solution {
public:
    bool capital(char c){
        return c>='A' && c<='Z';
    }
    string makeGood(string s) {
        deque<char>dq;
        for(char c:s){
            if(!dq.empty() && ((capital(c) && dq.back()==c-'A'+'a') || !(capital(c)) && dq.back()==c+'A'-'a'))
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