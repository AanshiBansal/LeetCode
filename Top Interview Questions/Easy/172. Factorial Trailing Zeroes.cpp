int trailingZeroes(int n) {
    int ans=0;
    long long five=5;
    while(five<=n){
        ans+=n/five;
        five*=5;
    }
    return ans;
}
