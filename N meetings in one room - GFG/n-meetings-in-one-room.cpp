// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool customSort(pair<int,int>A,pair<int,int>B){
    return A.second<B.second;
}
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v(n);
        int ans=0;
        for(int i=0;i<n;i++){
            v[i]={start[i],end[i]};
        }
        sort(v.begin(),v.end(),customSort);
        int ends=-1;
        for(int i=0;i<n;i++){
            if(v[i].first>ends){
                ans++;
                ends=v[i].second;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends