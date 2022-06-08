class Solution {
private:
    bool isPalindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int removePalindromeSub(string s) {
        return isPalindrome(s)?1:2;
    }
};