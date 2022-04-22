class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>s;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && temperatures[s.top()]<=temperatures[i])
                s.pop();
            ans[i]=!s.empty()?s.top()-i:0;
            s.push(i);
        }
        return ans;
    }
};