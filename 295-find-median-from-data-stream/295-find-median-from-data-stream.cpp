class MedianFinder {
private: 
    int size;
    priority_queue<int>first;
    priority_queue<int, vector<int>, greater<int>>second;
public:
    MedianFinder() {
        size=0;
        first=priority_queue<int>();
        second=priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        if(size==0){
            first.push(num);
            size++;
            return;
        }
        if(size%2==0){
            if(first.top()>=num){
                first.push(num);
            }else{
                second.push(num);
                first.push(second.top());
                second.pop();
            }
        }else{
            if(first.top()<=num){
                second.push(num);
            }else{
                first.push(num);
                second.push(first.top());
                first.pop();
            }
        }
        size++;
    }
    
    double findMedian() {
        if(size%2==0)
            return double(first.top()+second.top())/2;
        return first.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */