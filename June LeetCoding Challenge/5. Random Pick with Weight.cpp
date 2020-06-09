vector<int>bag;
int sum;
Solution(vector<int>& w) {
    bag = w;
    for(int i=1;i<bag.size();i++)
        bag[i]+=bag[i-1];
    sum=bag[bag.size()-1];
}
int pickIndex() {
    int ans= rand()%sum + 1;
    int i=0;
    int j=bag.size()-1;
    while(1){
        if(i>=j)
            return i;
        int mid=(i+j)/2;
        if(bag[mid]==ans)
            return mid;
        if(bag[mid]<ans)
            i=mid+1;
        else
            j=mid;
    }
    return 0;
}
};
