class Solution {
public:
    int minPartitions(string n) {
        char ans='0';
        for(char c:n){
            ans=max(ans,c);
        }
        return ans-'0';
    }
};