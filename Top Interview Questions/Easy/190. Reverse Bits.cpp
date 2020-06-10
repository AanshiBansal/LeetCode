uint32_t reverseBits(uint32_t n) {
    uint32_t ans=0;
    for(int i=0;i<32;i++){
        int bit=n&1;
        n=n>>1;
        ans=ans<<1;
        ans=ans|bit;
    }
    return ans;
}
