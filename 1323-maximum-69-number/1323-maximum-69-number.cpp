class Solution {
public:
    int maximum69Number (int num) {
        int temp=num;
        int factor=0;
        int maxi=-1;
        while(temp>0){
            if(temp%10==6)
                maxi=factor;
            factor++;
            temp/=10;
        }
        if(maxi>=0)
        num+=3*pow(10,maxi);
        return num;
    }
};