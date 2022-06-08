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
        int count=0;
        if(isPalindrome(s))
            return 1;
        // for(char c:s){
        //     if(c=='a')
        //         count++;
        //     else
        //         count--;
        // }
        // return count==0?1:2;
        return 2;
    }
};