//dp

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>ans(num+1);
        ans[0]=0;
        int start=1;
        int size=1;
        while(start<=num){
            int j=0;
            for(int j=0;j<size&&start+j<=num;j++){
                ans[start+j]=1+ans[j];
            }
            if(start+j>num)
                break;
            size*=2;
            start=size;
        }
        return ans;
    }
};
