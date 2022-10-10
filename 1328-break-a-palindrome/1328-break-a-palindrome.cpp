class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1)
            return "";
        bool flag=true;
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a'){
                flag=false;
                break;
            }
        }
        if(flag){
            palindrome[n-1]='b';
            return palindrome;
        }
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                break;
            }
        }
        return palindrome;
    }
};