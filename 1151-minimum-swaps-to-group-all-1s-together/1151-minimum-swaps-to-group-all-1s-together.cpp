class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n=data.size();
        int maxones=0;
        int count=0;
        for(int d:data)
            count+=d;
        
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=data[i];
            if(i>=count){
                curr-=data[i-count];
            }
            maxones=max(maxones,curr);
        }
        return count-maxones;
    }
};