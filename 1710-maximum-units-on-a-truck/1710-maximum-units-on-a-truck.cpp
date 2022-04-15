bool comparator(vector<int>&a,vector<int>&b){
    return a[1]>b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comparator);
        int ans=0;
        int i=0;
        while(i<boxTypes.size() && truckSize>0){
            ans+=min(boxTypes[i][0],truckSize)*boxTypes[i][1];
            truckSize-=boxTypes[i][0];
            i++;
        }
        return ans;
    }
};