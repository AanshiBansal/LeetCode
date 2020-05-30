//Complement a positive integer
// check if a bit is set
//num&(1<<i)==0 represents an unset (i+1)bit
//Approach: When first set bit is found - start complementing

class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        bool start=false;
        for(int i=31;i>=0;i--){
            int check=num & (1<<i);
            if(check!=0)
                start=true;
            ans=ans<<1;
            if(start && check==0)
                ans=ans|1;
        }
        return ans;
    }
};
};
