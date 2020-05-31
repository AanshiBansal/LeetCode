//HashMap

bool fn(pair<int,char>a, pair<int,char>b){
        return b.first<a.first;
}
class Solution {
public:
    
    string frequencySort(string s) {
        vector<pair<int,char> >mp(256);
        for(int i=0;i<256;i++){
            mp[i].first=0;
            mp[i].second=char(i);
        }
        for(int i=0;i<s.size();i++){
                mp[s[i]].first++;
        }
        sort(mp.begin(),mp.end(),fn);
        string ans="";
        for(auto i:mp){
            for(int j=0;j<i.first;j++)
                ans+=char(i.second);
        }
        return ans;
    }
};
