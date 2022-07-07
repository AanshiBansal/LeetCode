class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size(), b = s2.size(), c = s3.size();
        if(a + b != c) return false;
        
        vector<int>curr(b + 1, 0), prev(b + 1, 0);
        prev[0] = 1; curr[0] = 1; //base case
        
        for(int i = 0; i <= a; i++) {
            for(int j = 0; j <= b; j++) {
                if(i == 0 && j == 0) continue; //base case
                bool froms1 = false, froms2 = false;
        
                if(i > 0 && s1[i- 1] == s3[i + j - 1]) froms1 = prev[j];
                if(j > 0 && s2[j - 1] == s3[i + j - 1]) froms2 = curr[j - 1];

                curr[j] = froms1 || froms2;
            }
            prev = curr; //swap curr with prev
        }
        
        return curr[b];
    }
};