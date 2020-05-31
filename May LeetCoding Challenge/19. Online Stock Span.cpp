//Stack

class StockSpanner {
public:
    stack<pair<int,int> >*s;
    int count=0;
    StockSpanner() {
        s=new stack<pair<int,int> >;
        count=0;
    }
    
    int next(int price) {
        count++;
        while(!s->empty()&&s->top().second<=price)
            s->pop();
        int start=0;
        if(!s->empty())
            start=s->top().first;
        int ans=count-start;
        s->push({count,price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
