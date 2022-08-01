class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        int nu=1;
        int de=1;
        if(m<n)
            swap(m,n);
        m+=n;
        while(n){
            nu*=m--;
            de*=n--;
            int gcd=__gcd(nu,de);
            nu/=gcd;
            de/=gcd;
        }
        return nu;
    }
};