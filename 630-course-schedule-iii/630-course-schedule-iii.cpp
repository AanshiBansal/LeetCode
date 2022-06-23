bool comparator(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comparator);
        priority_queue<int>pq;
        int time=0;
        for(int i=0;i<courses.size();i++){
            if(time+courses[i][0]<=courses[i][1]){
                pq.push(courses[i][0]);
                time+=courses[i][0];
            }else{
                pq.push(courses[i][0]);
                time+=courses[i][0];
                time-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};