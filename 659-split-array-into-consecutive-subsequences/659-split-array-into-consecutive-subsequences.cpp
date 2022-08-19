class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int p1=0,p2=0,p3=0;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i-1]!=nums[i]-1){
                if(p1!=0 || p2!=0)
                    return false;
                p1=0;p2=0;p3=0;
            }
            int count=1;
            while(i+1<nums.size() && nums[i+1]==nums[i]){
                count++;
                i++;
            }
            if(count<p1+p2)
                return false;
            int c2=p1;
            int c3=p2+min(p3,count-p1-p2);
            int c1=count-c2-c3;
            p1=c1;p2=c2;p3=c3;
            //cout<<nums[i]<<" "<<p1<<" "<<p2<<" "<<p3<<endl;
        }
        if(p1!=0 || p2!=0)
            return false;
        return true;
    }
};