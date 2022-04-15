class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n=data.size();
        int maxones=0;
        int count=0;
        for(int d:data)
            count+=d;
        int end=0;
        int curr=0;
        while(end<n){
            curr+=data[end];
            if(end>=count){
                curr-=data[end-count];
            }
            maxones=max(maxones,curr);
            end++;
        }
        return count-maxones;
    }
};