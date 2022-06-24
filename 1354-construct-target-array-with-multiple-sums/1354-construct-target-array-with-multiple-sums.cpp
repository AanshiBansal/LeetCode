class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        priority_queue<int>pq;
        long long sum=0;
        for(int i=0;i<n;i++){
            pq.push(target[i]);
            sum+=target[i];
        }
        while(pq.top()!=1){
            int top=pq.top();
            pq.pop();
            sum-=top;
            if(sum==1)
                return true;
            if(sum<1 || top<sum)
                return false;
            int prev=top%sum;
            if(prev<1)
                return false;
            sum+=prev;
            pq.push(prev);
        }
        return true;
    }
};