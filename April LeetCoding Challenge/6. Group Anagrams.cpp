//hashmap
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<vector<int>,vector<string> >mp;
    for(int i=0;i<strs.size();i++){
        vector<int>count(26,0);
        for(int j=0;j<strs[i].size();j++){
            count[strs[i].at(j)-'a']++;
        }
        if(mp.find(count)==mp.end()){
            vector<string>ans;
            ans.push_back(strs[i]);
            mp[count]=ans;
        }
        else
            mp[count].push_back(strs[i]);
    }
    vector<vector<string> >sol;
    for(auto i =mp.begin();i!=mp.end();i++){
        sol.push_back(i->second);
    }
    return sol;
}
