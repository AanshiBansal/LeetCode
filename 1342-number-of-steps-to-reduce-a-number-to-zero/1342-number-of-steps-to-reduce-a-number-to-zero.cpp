class Solution {
public:
    int numberOfSteps (int num) {
        if(num==0)
            return 0;
        int ans=0;
        while(num>1){
            if(num%2==0)
                ans++;
            else
                ans+=2;
            num=num/2;
        }
        return ans+1;
    }
};