//Calculating nCr
int uniquePaths(int m, int n) {
    m--;n--;
    int nu=1;
    int de=1;
    m=m+n;
    if(m-n<n)
        n=m-n;
    while(n){
        nu*=m;
        de*=n;
        int gcd=__gcd(nu,de);
        nu/=gcd;
        de/=gcd;
        m--;
        n--;
    }
    return nu;
}
