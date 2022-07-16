typedef long long ll;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ll n=bloomDay.size();
        ll total=1;
        total*=m;
        total*=k;
        if(total>n)
            return -1;
        int high=1;
        int low=1;
        for(int day:bloomDay){
            high=max(high,day);
        }
        while(low<high){
            int mid=low+(high-low)/2;
            int b=0;
            int curr=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid)
                    curr++;
                else
                    curr=0;
                if(curr==k){
                    b++;
                    curr=0;
                }
            }
            //cout<<low<<" "<<high<<" "<<mid<<" "<<b<<endl;
            if(b>=m){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};