//Binary Search
int hIndex(vector<int>& citations) {
    int size=citations.size();
    int i=0;
    int j=size-1;
    while(i<=j){
        if(i==j){
            if(citations[i]>=size-i)
                return size-i;
            else
                return 0;
        }
        int mid=(i+j)/2;
        if(citations[mid]>=size-mid)
            j=mid;
        else
            i=mid+1;
    }
    return 0;
}
