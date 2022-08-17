class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string code[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>ans;
        for(string word : words){
            string temp="";
            for(char c:word){
                temp+=code[c-'a'];
            }
            ans.insert(temp);
        }
        return ans.size();
    }
};