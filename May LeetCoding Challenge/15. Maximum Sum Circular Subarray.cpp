//Kadane's Algorithm

class Solution {
public:
    int maxSubArray(const vector<int> &A) {
        int ans=0;
        if(A.size()==0)
        return ans;
        int sum=A[0];
        ans=A[0];
        for(int i=1;i<A.size();i++){
            sum=max(sum+A[i],A[i]);
            ans=max(ans,sum);
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        int ans1=maxSubArray(A);
        int sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            A[i]*=-1;
        }
        int ans2=maxSubArray(A);
        //When all A[i] are negative
        if(ans2+sum==0)
            return ans1;
        return max(ans1,sum+ans2);
    }
    
};
