//priority queue
int twoCitySchedCost(vector<vector<int>>& costs) {
    int n=costs.size();
    priority_queue<pair<int,int> >pq;
    for(int i=0;i<n;i++)
        pq.push({abs(costs[i][0]-costs[i][1]),i});
    int ans=0;
    vector<int>cityCount(2,0);
    while(!pq.empty()){
        int person=pq.top().second;
        int city=costs[person][0]>costs[person][1]?1:0;
        pq.pop();
        if(cityCount[city]==n/2)
            city=(city==0)?1:0;
        cityCount[city]++;
        ans+=costs[person][city];
    }
    return ans;
}
