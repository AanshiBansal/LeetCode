class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>count(26,0);
        for(char c:magazine){
            count[c-'a']++;
        }
        for(char c:ransomNote){
            count[c-'a']--;
        }
        for(int i=0;i<26;i++){
            if(count[i]<0)
                return false;
        }
        return true;
    }
};