class Solution {
public:
    int arrangeCoins(int n) {
    	//brute force
        /*long long ans=0;
        for(int i=1;;i++){
            ans+=i;
            if(ans>n)
                return i-1;
            if(ans==n)
                return i;
        }
        return 0;*/
        
        //binary search
        int mid=sqrt(2*long(n));
        int low=0;
        while(low!=mid){
            long long coins=(mid*long(mid+1))/2;
            if(coins==n)
                return mid;
            if(coins>n)
                mid--; 
            if(coins<n)
            {
                low=mid;
                mid++;
            }
        }
        return low;
        
        //solving inequality
        //return sqrt(2 * long(n) + 0.25) - 0.5;
    }
};
