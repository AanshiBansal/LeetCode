class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n<=2)
            return 1;
        vector<int>prev(3,1);
        prev[0]=0;
        for(int i=3;i<=n;i++){
            int curr=prev[0]+prev[1]+prev[2];
            prev[0]=prev[1];
            prev[1]=prev[2];
            prev[2]=curr;
        }
        return prev[2];
    }
};