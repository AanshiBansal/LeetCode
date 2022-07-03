// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int diff=abs(arr[0]-x);
//         int a=-1,b=0;
//         //vector<int>ans;
//         for(int i=1;i<arr.size();i++){
//             if(abs(arr[i]-x)<=diff){
//                 a=i-1;
//                 b=i;
//                 diff=abs(arr[i]-x);
//             }else{
//                 break;
//             }
//         }
//         while(k--){
//             if(a<0){
//                 //ans.push_back(arr[b]);
//                 b++;
//                 continue;
//             }
//             if(b==arr.size()){
//                 //ans.push_back(arr[a]);
//                 a--;
//                 continue;
//             }
//             if(abs(arr[a]-x)<=abs(arr[b]-x)){
//                 //ans.push_back(arr[a]);
//                 a--;
//             }else{
//                 //ans.push_back(arr[b]);
//                 b++;
//             }
//         }
//         //sort(ans.begin(),ans.end());
//         return vector<int>(arr.begin()+a+1,arr.begin()+b);
//     }
// };


// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int i=0,j=arr.size()-1;
//         while((j-i+1)>k){
//             if(abs(arr[i]-x)<=abs(arr[j]-x))
//                 j--;
//             else
//                 i++;
//         }
//         return vector<int>(arr.begin()+i,arr.begin()+j+1);
//     }
// };

int lowerBound(vector<int>&a, int target){
    int low=0;
    int high=a.size();
    while(low<high){
        int mid=low+(high-low)/2;
        if(a[mid]>=target){
            high=mid;
        }else{
            low=mid+1;
        }
    }
    return low;
}

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int high=lowerBound(arr,x);
        int low=high-1;
        int n=arr.size();
        while(high-low-1<k){
            if(low<0){
                break;
            }
            if(high==n){
                low--;
                continue;
            }
            if(abs(x-arr[low])<=abs(x-arr[high])){
                low--;
            }else
                high++;
        }
        return vector<int>(arr.begin()+(low+1),arr.begin()+(low+1+k));
    }
};