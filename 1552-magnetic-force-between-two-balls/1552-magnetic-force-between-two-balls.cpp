class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int low=1;
        int high=1000000000;
        int ans=1;
        sort(position.begin(),position.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int balls=1;
            int prev=position[0];
            for(int i=1;i<position.size();i++){
                if(position[i]-prev>=mid){
                    balls++;
                    prev=position[i];
                }
            }
            if(balls>=m)
                ans=max(ans,mid);
            if(balls<m){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};