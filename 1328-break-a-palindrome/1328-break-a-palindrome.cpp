class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1)
            return "";
        int flag=n/2;
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a'){
                flag=i;
                break;
            }
        }
        if(flag==n/2)
            palindrome[n-1]='b';
        else
            palindrome[flag]='a';
        return palindrome;
    }
};