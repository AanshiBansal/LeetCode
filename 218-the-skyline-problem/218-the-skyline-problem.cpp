// class Solution {
// public:
//     vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//         int n=buildings.size();
//         vector<vector<int>>b;
//         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
//         b.push_back(buildings[0]);
//         for(int i=1;i<n;i++){
//             pq.push(buildings[i]);
//         }
//         while(!pq.empty()){
//             vector<int>curr=pq.top();
//             pq.pop();
//             int itr=b.size()-1;
//             int h1=b[itr][2];
//             int h2=curr[2];
//             // gap between buildings
//             if(b[itr][1]<curr[0]){
//                 b.push_back({b[itr][1],curr[0],0});
//                 b.push_back(curr);
//                 continue;
//             }
//             // equal height
//             if(h2==h1){
//                 b[itr][1]=max(b[itr][1],curr[1]);
//                 continue;
//             }
//             // next building is smaller in size
//             if(h2<h1){
//                 // ends before first building
//                 if(b[itr][1]>=curr[1])
//                     continue;
//                 // some part remaining
//                 if(!pq.empty() && pq.top()[0]<b[itr][1])
//                     pq.push({b[itr][1],curr[1],h2});
//                 else
//                     b.push_back({b[itr][1],curr[1],h2});
//                 continue;
//             }
//             // next building is taller
//             int end=b[itr][1];
//             b[itr][1]=curr[0];
//             if(b[itr][1]==b[itr][0])
//                 b.pop_back();
//             b.push_back(curr);
//             if(curr[1]<end){
//                 pq.push({curr[1],end,h1});
//             }
//         }
//         vector<vector<int>>ans;
//         for(int i=0;i<b.size();i++){
//             if(i==0 || b[i][2]!=b[i-1][2])
//                 ans.push_back({b[i][0],b[i][2]});
//         }
//         ans.push_back({b[b.size()-1][1],0});
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int,int>>pq;
        vector<vector<int>>ans;
        //buildings.push_back({INT_MAX,INT_MAX,0});
        for(int i=0;i<buildings.size();i++){
            while(!pq.empty() && pq.top().second<buildings[i][0]){
                int x=pq.top().second;
                pq.pop();
                while(!pq.empty() && pq.top().second<=x){
                    pq.pop();
                }
                int h=pq.empty()?0:pq.top().first;
                ans.push_back({x,h});
            }
            if(ans.size()!=0 && ans[ans.size()-1][0]==buildings[i][0]){
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],buildings[i][2]);
            }else{
                if(ans.size()==0 || ans[ans.size()-1][1]<buildings[i][2]){
                    ans.push_back({buildings[i][0],buildings[i][2]});
                }
            }
            pq.push({buildings[i][2],buildings[i][1]});
        }
        while(!pq.empty()){
            int x=pq.top().second;
            pq.pop();
            while(!pq.empty() && pq.top().second<=x){
                pq.pop();
            }
            int h=pq.empty()?0:pq.top().first;
            ans.push_back({x,h});
        }
        return ans;
    }
};