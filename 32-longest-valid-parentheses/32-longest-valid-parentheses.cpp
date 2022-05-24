// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         stack<int>st;
//         int ans=0;
//         st.push(-1);
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='('){
//                 st.push(i);
//             }else{
//                 st.pop();
//                 if(st.empty()){
//                     st.push(i);
//                 }else{
//                     ans=max(ans,i-st.top());
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
    public: int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
};