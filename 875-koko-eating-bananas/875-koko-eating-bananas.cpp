class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=1000000000;
        while(low<high){
            int mid=low+(high-low)/2;
            int hours=0;
            for(int bananas:piles){
                hours+=bananas/mid;
                if(bananas%mid!=0)
                    hours++;
            }
            if(hours<=h){
                high=mid;
            }else
                low=mid+1;
        }
        return low;
    }
};