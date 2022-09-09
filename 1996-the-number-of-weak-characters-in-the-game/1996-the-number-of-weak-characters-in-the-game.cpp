class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end());
        int n=properties.size();
        int maxi=0;
        int ans=0;
        int ptr=n-1;
        for(int i=n-2;i>=0;i--){
            while(ptr>i && properties[ptr][0]>properties[i][0]){
                maxi=max(maxi,properties[ptr][1]);
                ptr--;
            }
            if(maxi>properties[i][1]){
                //cout<<i<<" "<<maxi<<" "<<ptr<<endl;
                ans++;
            }
        }
        return ans;
    }
};