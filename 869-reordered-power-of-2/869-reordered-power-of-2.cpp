class Solution {
private:
    vector<int>fn(int n){
        vector<int>count(10,0);
        while(n){
            int r=n%10;
            count[r]++;
            n/=10;
        }
        return count;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<int>org=fn(n);
        for(int i=0;i<31;i++){
            int num=1<<i;
            vector<int>curr=fn(num);
            bool flag=true;
            for(int j=0;j<10;j++){
                if(org[j]!=curr[j]){
                    flag=false;
                    break;
                }
            }
            if(flag)
                return true;
        }
        return false;
    }
};