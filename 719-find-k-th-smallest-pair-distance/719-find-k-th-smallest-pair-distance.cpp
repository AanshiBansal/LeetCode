// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         priority_queue<int>pq;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 pq.push(abs(nums[j]-nums[i]));
//                 if(pq.size()>k)
//                     pq.pop();
//             }
//         }
//         return pq.top();
//     }
// };

// typedef pair<int,pair<int,int>> pr;
// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         priority_queue<pr,vector<pr>,greater<pr>>pq;
//         for(int i=0;i<n-1;i++){
//             pq.push({nums[i+1]-nums[i],{i,i+1}});
//         }
//         int count=0;
//         while(!pq.empty()){
//             int val=pq.top().first;
//             int x=pq.top().second.first;
//             int y=pq.top().second.second;
//             pq.pop();
//             count++;
//             if(count==k)
//                 return val;
//             if(y+1<n){
//                 pq.push({nums[y+1]-nums[x],{x,y+1}});
//             }
//         }
//         return 0;
//     }
// };

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[n-1]-nums[0];
        while(low<high){
            int mid=low+(high-low)/2;
            int count=0;
            int right=1;
            for(int i=0;i<n;i++){
                while(right<n && nums[right]-nums[i]<=mid){
                    right++;
                }
                count+=(right-i-1);
            }
            //cout<<low<<" "<<high<<" "<<mid<<" "<<count<<endl;
            if(count>=k){
                high=mid;
            }else
                low=mid+1;
        }
        return low;
    }
};