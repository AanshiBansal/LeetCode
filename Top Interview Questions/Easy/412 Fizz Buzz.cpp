vector<string> fizzBuzz(int n) {
    vector<string>ans(n);
    for(int i=0;i<n;i++)
        ans[i]=to_string(i+1);
    for(int i=2;i<n;i=i+3)
        ans[i]="Fizz";
    for(int i=4;i<n;i=i+5)
        if((i+1)%3==0)
           ans[i]+="Buzz";
        else   
        ans[i]="Buzz";
    return ans;
}
