class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<0)
            return false;
        for(int i=0;;i++){
            long long s=i*long(i);
            if(s==num)
                return true;
            if(s>num || s>=INT_MAX)
                break;
        }
        return false;
    }
};
