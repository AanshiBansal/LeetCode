//Similar to finding loop in a linked list
int sum(int n){
    int ans=0;
    while(n){
        int temp=n%10;
        ans+=temp*temp;
        n/=10;
    }
    return ans;
}
bool isHappy(int n) {
    int slow=n;
    int fast=n;
    do{
        slow=sum(slow);
        fast=sum(sum(fast));
        if(slow==1 || fast==1)
            return true;
        
    }while(slow!=fast);
    return slow==1;
}
