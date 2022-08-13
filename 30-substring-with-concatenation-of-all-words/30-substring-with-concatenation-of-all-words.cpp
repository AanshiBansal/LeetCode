class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int size=words[0].size();
        int n=words.size();
        unordered_map<string,int>count;
        for(int i=0;i<n;i++){
            count[words[i]]++;
        }
        for(int i=0;i<s.size();i++){
            unordered_map<string,int>temp;
            bool flag=true;
            for(int j=0,k=i;j<n && k+size<=s.size();j++,k+=size){
                if(count.find(s.substr(k,size))!=count.end())
                    temp[s.substr(k,size)]++;
                else{
                    flag=false;
                    break;
                }
            }
            int c=0;
            if(flag){
                for(auto itr=temp.begin();itr!=temp.end();itr++){
                    if(count[itr->first]!=itr->second){
                        flag=false;
                        break;
                    }else
                        c+=itr->second;
                        
                }
            }
            if(flag && c==n)
                ans.push_back(i);
        }
        return ans;
    }
};