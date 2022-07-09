class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        int n=buses.size();
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
       
        int index=0;
        int last=-1;
        int count=0;
        for(int i=0;i<n;i++){
            count=0;
            last=-1;
            while(count<capacity && index<passengers.size() && passengers[index]<=buses[i]){
                count++;
                last=index;
                index++;
            }
        }
        if(last==-1 || (count<capacity && passengers[last]!=buses[n-1]))
            return buses[n-1];
        
        while(last-1>=0 && passengers[last]-1==passengers[last-1]){
            last--;
        }
        return passengers[last]-1;
        
    }
};