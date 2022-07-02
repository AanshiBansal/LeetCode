class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(verticalCuts.begin(),verticalCuts.end());
        sort(horizontalCuts.begin(),horizontalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int maxiH=horizontalCuts[0];
        int maxiW=verticalCuts[0];
        for(int i=1;i<horizontalCuts.size();i++){
            maxiH=max(maxiH, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i=1;i<verticalCuts.size();i++){
            maxiW=max(maxiW, verticalCuts[i]-verticalCuts[i-1]);
        }
        // long long ans=1;
        // ans*=maxiH;
        // ans*=maxiW;
        // ans%=1000000007;
        return long(maxiH)*maxiW%1000000007;
    }
};