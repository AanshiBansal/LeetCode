bool perSqu(int n){
    int sq=sqrt(n);
    return n==sq*sq;
}
int numSquares(int n) {
    if(perSqu(n))
        return 1;
    while(n%4==0)
        n/=4;
    if(n%8==7)
        return 4;
    for(int i=1;i*i<n;i++){
        if(perSqu(n-i*i))
            return 2;
    }
    return 3;
}
