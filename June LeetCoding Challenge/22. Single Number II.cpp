//Bit Manipulation
int singleNumber(vector<int>& A) {
    vector<int>count(32,0);
    for(int i=0;i<32;i++){
        for(int j=0;j<A.size();j++){
            int temp=A[j]>>i;
            temp=temp&1;
            if(temp==1)
            count[i]++;
        }
    }
    int ans=0;
    for(int i=31;i>=0;i--){
        ans=ans<<1;
        if(count[i]%3!=0)
        ans=ans|1;
    }
    return ans;
}
