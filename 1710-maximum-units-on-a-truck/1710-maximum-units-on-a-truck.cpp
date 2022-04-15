bool comparator(vector<int>&a,vector<int>&b){
    return a[1]>b[1];
}
class Solution {
public:
    // int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    //     sort(boxTypes.begin(),boxTypes.end(),comparator);
    //     int ans=0;
    //     int i=0;
    //     while(i<boxTypes.size() && truckSize>0){
    //         ans+=min(boxTypes[i][0],truckSize)*boxTypes[i][1];
    //         truckSize-=boxTypes[i][0];
    //         i++;
    //     }
    //     return ans;
    // }
    // Counting Sort
    // Time: O(n), Space: O(1)
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans=0;
        vector<int>count(1001,0);
        for(int i=0;i<boxTypes.size();i++){
            count[boxTypes[i][1]]+=boxTypes[i][0];
        }
        int i=1000;
        while(i>0 && truckSize>0){
            ans+=min(count[i],truckSize)*i;
            truckSize-=count[i];
            i--;
        }
        return ans;
    }
};