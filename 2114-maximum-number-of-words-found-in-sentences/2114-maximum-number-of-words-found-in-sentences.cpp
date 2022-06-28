class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        for(string sentence: sentences){
            int count=0;
            for(char c:sentence)
                if(c==' ')
                    count++;
            ans=max(ans,count+1);
        }
        return ans;
    }
};