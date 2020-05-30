//Whether a string can be generated from characters of another string

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>m(26,0);
        for(int i=0;i<magazine.size();i++)
            m[magazine.at(i)-'a']++;
        for(int i=0;i<ransomNote.size();i++){
            m[ransomNote.at(i)-'a']--;
            if(m[ransomNote.at(i)-'a']<0)
                return false;
        }
        return true;
    }
};
