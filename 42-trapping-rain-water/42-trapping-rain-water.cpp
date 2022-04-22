class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        vector<int>right_max(n);
        right_max[n-1]=0;
        for(int i=n-2;i>=0;i--){
            right_max[i]=max(right_max[i+1],height[i+1]);
        }
        int left_max=0;
        for(int i=0;i<n;i++){
            ans+=max(min(left_max,right_max[i])-height[i],0);
            left_max=max(left_max,height[i]);
        }
        return ans;
    }
};