//local maximas and minimas in a graph
int maxProfit(vector<int>& prices) {
    int ans=0;
    bool buy=true;
    int prev=INT_MAX;
    int buy_index=0;
    for(int i=0;i<prices.size()-1;i++){
        if(buy){
            if(prev>=prices[i]&& prices[i]<prices[i+1]){
                buy_index=i;
                buy=false;
            }
        }
        else{
            if(prev<=prices[i]&& prices[i]>prices[i+1]){
                ans+=prices[i]-prices[buy_index];
                buy=true;
            }
        }
        prev=prices[i];
    }
    if(!buy)
        ans+=prices[prices.size()-1]-prices[buy_index];
    return ans;
}
