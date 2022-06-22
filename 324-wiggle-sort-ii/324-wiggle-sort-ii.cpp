class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>mp(5001,0);
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int itr=0;
        int n=nums.size();
        n--;
        int even=(n%2==0)?n:n-1;
        int odd=(n%2==1)?n:n-1;
        for(int i=even;i>=0;i-=2){
            while(mp[itr]==0){
                itr++;
            }
            nums[i]=itr;
            mp[itr]--;
        }
        for(int i=odd;i>=0;i-=2){
            while(mp[itr]==0){
                itr++;
            }
            nums[i]=itr;
            mp[itr]--;
        }
    }
};