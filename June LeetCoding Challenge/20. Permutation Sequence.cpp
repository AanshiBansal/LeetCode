string getPermutation(int n, int k) {
    vector<double>fact(n);
    vector<bool>present(n+1,false);
    fact[0]=1;
    for(int i=1;i<n;i++)
        fact[i]=fact[i-1]*i;
    string ans="";
    for(int i=n;i>=1;i--){
        int num=ceil(k/fact[i-1]);
        int j=1;
        while(1){
            if(present[j]==false)
                num--;
            if(num==0)
                break;
            j++;
        }
        ans+=to_string(j);
        present[j]=true;
        k-=(ceil(k/fact[i-1])-1)*fact[i-1];
    }
    return ans;
}
