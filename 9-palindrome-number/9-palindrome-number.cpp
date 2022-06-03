class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0))
            return false;
        int reverse=0;
        int num=x;
        while(num>reverse){
            reverse*=10;
            reverse+=(num%10);
            num/=10;
        }
        return reverse==num || num==reverse/10;
    }
};