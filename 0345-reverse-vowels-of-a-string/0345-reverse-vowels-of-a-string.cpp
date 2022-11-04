class Solution {
private:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
public:
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            while(i<s.size() && isVowel(s[i])==false){
                i++;
            }
            while(j>=0 && isVowel(s[j])==false){
                j--;
            }
            if(i<j)
                swap(s[i],s[j]);
            i++;j--;
        }
        return s;
    }
};