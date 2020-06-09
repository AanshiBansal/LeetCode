vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end());
    vector<vector<int> >ans(people.size(),vector<int>(2,INT_MAX));
    for(int i=0;i<people.size();i++){
        int count=people[i][1];
        int j=0;
        while(count!=0){
            if(ans[j][0]>=people[i][0])
                count--;
            j++;
        }
        while(ans[j][0]!=INT_MAX)
            j++;
        ans[j]=people[i];
    }
    return ans;
}
