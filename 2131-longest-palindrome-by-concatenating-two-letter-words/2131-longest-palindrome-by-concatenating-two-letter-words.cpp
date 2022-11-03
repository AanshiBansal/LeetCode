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
                if(count%2 == 1 && middle==false){
                    ans+=2;
                    middle=true;
                }
                if(count%2==1)
                    count--;
                ans+=(count*2);
            }else{
                string reverse="aa";
                reverse[0]=word[1];
                reverse[1]=word[0];
                int count2=mp.find(reverse)!=mp.end() ? mp[reverse] :0;
                ans+=(min(count,count2)*2);
            }
        }
        return ans;
    }
};