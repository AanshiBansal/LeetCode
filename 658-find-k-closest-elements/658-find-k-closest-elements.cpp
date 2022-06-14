class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int diff=abs(arr[0]-x);
        int a=-1,b=0;
        vector<int>ans;
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-x)<=diff){
                a=i-1;
                b=i;
                diff=abs(arr[i]-x);
            }else{
                break;
            }
        }
        //cout<<a<<" "<<b<<endl;
        while(k--){
            if(a<0){
                ans.push_back(arr[b]);
                b++;
                continue;
            }
            if(b==arr.size()){
                ans.push_back(arr[a]);
                a--;
                continue;
            }
            if(abs(arr[a]-x)<=abs(arr[b]-x)){
                ans.push_back(arr[a]);
                a--;
            }else{
                ans.push_back(arr[b]);
                b++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};