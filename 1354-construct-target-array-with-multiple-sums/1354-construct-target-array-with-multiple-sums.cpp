class Solution {
public:
    bool isPossible(vector<int>& target) {
        // sort(target.begin(),target.end());
        // int n=target.size();
        // priority_queue<int,vector<int>,greater<int>>pq;
        // for(int i=0;i<n;i++){
        //     pq.push(1);
        // }
        // int sum=n;
        // int i=0;
        // while(i<n && target[i]==1){
        //     pq.pop();
        //     i++;
        // }
        // while(!pq.empty()){
        //     if(target[i]<sum)
        //         return false;
        //     int top=pq.top();
        //     pq.pop();
        //     if(sum==target[i]){
        //         sum-=top;
        //         sum+=target[i];
        //         i++;
        //     }else{
        //         pq.push(sum);
        //         sum+=sum;
        //         sum-=top;
        //     }
        // }
        // return true;
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