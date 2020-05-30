//Binary Search

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int util(long long i,long long j){
        if(i==j)
            return i;
        long long mid=(i+j)/2;
        bool check=isBadVersion(mid);
        if(check)
            return util(i,mid);
        else
            return util(mid+1,j);
    }
    int firstBadVersion(int n) {
        return util(1,n);
    }
};
