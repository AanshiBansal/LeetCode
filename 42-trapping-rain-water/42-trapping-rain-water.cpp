// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int ans=0;
//         int n=height.size();
//         vector<int>right_max(n);
//         right_max[n-1]=0;
//         for(int i=n-2;i>=0;i--){
//             right_max[i]=max(right_max[i+1],height[i+1]);
//         }
//         int left_max=0;
//         for(int i=0;i<n;i++){
//             ans+=max(min(left_max,right_max[i])-height[i],0);
//             left_max=max(left_max,height[i]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int left_max=0;
        int right_max=0;
        int i=0;
        int j=height.size()-1;
        while(i<=j){
            if(left_max<right_max){
                ans+=max(left_max-height[i],0);
                left_max=max(left_max,height[i]);
                i++;
            }else{
                ans+=max(right_max-height[j],0);
                right_max=max(right_max,height[j]);
                j--;
            }
        }
        return ans;
    }
};