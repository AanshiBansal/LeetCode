class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n=data.size();
        int ans=INT_MAX;
        int count=0;
        for(int d:data){
            if(d==1)
                count++;
        }
        if(count==0)
            return 0;
        for(int i=1;i<n;i++)
            data[i]+=data[i-1];
        for(int i=0;i+count<n;i++){
            ans=min(ans,count-(data[i+count]-data[i]));
        }
        return min(ans,count-data[count-1]);
    }
};