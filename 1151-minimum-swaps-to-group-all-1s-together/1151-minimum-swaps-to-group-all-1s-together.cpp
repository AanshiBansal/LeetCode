class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n=data.size();
        int maxones=0;
        int count=0;
        for(int d:data){
            if(d==1)
                count++;
        }
        int start=0;
        int end=0;
        int curr=0;
        while(end<n){
            curr+=data[end++];
            if(end-start>count){
                curr-=data[start++];
            }
            maxones=max(maxones,curr);
        }
        return count-maxones;
    }
};