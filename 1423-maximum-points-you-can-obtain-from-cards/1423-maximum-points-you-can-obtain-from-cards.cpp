class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int size=n-k;
        int curr=0;
        for(int i=0;i<size;i++){
            curr+=cardPoints[i];
        }
        int mini=curr;
        for(int i=0;i+size<n;i++){
            curr-=cardPoints[i];
            curr+=cardPoints[i+size];
            if(curr<mini){
                mini=curr;
            }
        }
        int ans=0;
        for(int num:cardPoints){
            ans+=num;
        }
        return ans-mini;
    }
};