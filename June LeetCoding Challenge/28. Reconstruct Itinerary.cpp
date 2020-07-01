void help(string src,unordered_map<string,priority_queue<string,vector<string>,greater<string> > >&adj,vector<string>&ans){
    while(!adj[src].empty()){
        string dest=adj[src].top();
        adj[src].pop();
        help(dest,adj,ans);
    }
    ans.push_back(src);
}
vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string,priority_queue<string,vector<string>,greater<string> > >adj;
    for(int i=0;i<tickets.size();i++)
        adj[tickets[i][0]].push(tickets[i][1]);
    vector<string>ans;
    help("JFK",adj,ans);
    reverse(ans.begin(),ans.end());
    return ans;
}
