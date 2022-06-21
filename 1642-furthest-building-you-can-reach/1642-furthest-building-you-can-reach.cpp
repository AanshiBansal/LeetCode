// class Solution {
// private:
//     int fn(int index,vector<int>& heights, int bricks, int ladders, vector<vector<vector<int>>>&dp){
//         if(index==heights.size()-1)
//             return index;
//         if(dp[index][bricks][ladders]!=-1)
//             return dp[index][bricks][ladders];
//         if(heights[index]>=heights[index+1])
//             return dp[index][bricks][ladders]=fn(index+1,heights,bricks,ladders,dp);
//         int ans=index;
//         if(ladders>0)
//             ans=max(ans,fn(index+1,heights,bricks,ladders-1,dp));
//         if(bricks>=heights[index+1]-heights[index])
//             ans=max(ans,fn(index+1,heights,bricks-(heights[index+1]-heights[index]),ladders,dp));
//         return dp[index][bricks][ladders]=ans;
//     }
// public:
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         int n=heights.size();
//         vector<vector<vector<int>>>dp(n,vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1)));
//         return fn(0,heights,bricks,ladders,dp);
//     }
// };

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        for(int i=0;i<heights.size()-1;i++){
            if(heights[i]>=heights[i+1])
                continue;
            int diff=heights[i+1]-heights[i];
            if(bricks>=diff){
                pq.push(diff);
                bricks-=diff;
                continue;
            }
            if(ladders==0){
                return i;
            }
            pq.push(diff);
            bricks-=diff;
            bricks+=pq.top();;
            pq.pop();
            ladders--;
        }
        return heights.size()-1;
    }
};