class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long reverse=0;
        int num=x;
        while(num>0){
            reverse*=10;
            reverse+=(num%10);
            num/=10;
        }
        return reverse==x;
    }
};