bool isPowerOfTwo(int n) {
    if(n<=0)
        return false;
    bool start=false;
    for(int i=0;i<32;i++){
        if(!start){
            if((n & 1)==1)
                start=true;
        }
        else{
            if((n & 1)==1)
                return false;
        }
        n=n>>1;
    }
    return true;
}
