bool comp(vector<int>&a, vector<int>&b){
    return a[0]>b[0] || (a[0] == b[0] && a[1]<b[1]);
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp);
        int n=people.size();
        for(int i=1;i<n;i++){
            vector<int>t=people[i];
            for(int j=i-1;j>=t[1];j--){
                people[j+1]=people[j];
            }
            people[t[1]]=t;
        }
        return people;
    }
};