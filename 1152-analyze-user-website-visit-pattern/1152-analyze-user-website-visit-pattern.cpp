struct custom{
    string username;
    int timestamp;
    string website;
    custom(string u, int t,string w){
        username=u;
        timestamp=t;
        website=w;
    };
};
bool comparator(custom &a, custom &b){
    if(a.username==b.username)
        return a.timestamp<b.timestamp;
    return a.username<b.username;
}
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n=username.size();
        vector<custom>data;
        for(int i=0;i<n;i++){
            data.push_back({username[i],timestamp[i],website[i]});
        }
        sort(data.begin(),data.end(),comparator);
        // for(int i=0;i<n;i++){
        //     cout<<data[i].username<<" "<<data[i].timestamp<<" "<<data[i].website<<endl;
        // }
        map<vector<string>,int>mp;
        for(int i=0;i<n;i++){
            string user=data[i].username;
            int end=i;
            while(end<n && data[end].username==user){
                end++;
            }
            end--;
            set<vector<string>>s;
            for(int x=i;x+2<=end;x++){
                for(int y=x+1;y+1<=end;y++){
                    for(int z=y+1;z<=end;z++){
                        if(s.find({data[x].website,data[y].website,data[z].website})==s.end()){
                            mp[{data[x].website,data[y].website,data[z].website}]++;
                            s.insert({data[x].website,data[y].website,data[z].website});
                        }
                    }
                }
            }
            i=end;
        }
        int count=0;
        vector<string>ans;
        for(auto pattern:mp){
            //cout<<pattern.first[0]<<" "<<pattern.first[1]<<" "<<pattern.first[2]<<" "<<" "<<pattern.second<<endl;
            if(pattern.second>count){
                count=pattern.second;
                ans=pattern.first;
            }
        }
        return ans;
    }
};