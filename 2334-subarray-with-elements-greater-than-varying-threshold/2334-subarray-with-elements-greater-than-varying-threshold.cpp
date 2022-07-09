class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n=nums.size();
        vector<int>prevS(n);
        vector<int>nextS(n);
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && nums[s.top()]>=nums[i]){
                s.pop();
            }
            prevS[i]=s.top();
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        s.push(n);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=n && nums[s.top()]>=nums[i]){
                s.pop();
            }
            nextS[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<n;i++){
            int size=nextS[i]-prevS[i]-1;
            if(nums[i]>threshold/size)
                return size;
        }
        return -1;
    }
};