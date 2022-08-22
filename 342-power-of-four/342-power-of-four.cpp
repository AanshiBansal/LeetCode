class Solution {
public:
    bool isPowerOfFour(int num) {
        for(int i=0;i<32;i=i+2){
            int check=1<<i;
            if(check==num)
                return true;
        }
        return false;
    }
};