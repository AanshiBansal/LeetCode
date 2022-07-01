class Solution {
private:
    bool satisfied(vector<int>&a, vector<int>&b){
        for(int i=0;i<128;i++){
            if(a[i]<b[i])
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        vector<int>ct(256,0);
        for(char c:t){
            ct[c]++;
        }
        int left=0,right=0;
        vector<int>sc(256,0);
        int length=INT_MAX;
        int start;
        while(right<s.size()){
            sc[s[right]]++;
            while(left<=right && satisfied(sc,ct)){
                //string curr=s.substr(left,right-left+1);
                if(right-left+1<length){
                    length=right-left+1;
                    start=left;
                }
                sc[s[left]]--;
                left++;
            }
            right++;
        }
        if(length==INT_MAX)
            return "";
        return s.substr(start,length);
    }
};