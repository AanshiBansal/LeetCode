class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(string s: words){
            mp[s]++;
        }
        int ans=0;
        bool middle=false;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            string word=itr->first;
            int count=itr->second;
            if(word[0]==word[1]){
                if(count%2 == 1){
                    if(middle==false){
                        ans+=2;
                        middle=true;
                    }
                    count--;
                }
                ans+=(count*2);
            }else{
                string rev=word;
                reverse(rev.begin(),rev.end());
                int count2=mp.find(rev)!=mp.end() ? mp[rev] :0;
                ans+=(min(count,count2)*2);
            }
        }
        return ans;
    }
};