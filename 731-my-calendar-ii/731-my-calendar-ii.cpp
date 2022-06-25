class MyCalendarTwo {
private:
    map<int,int>booked;
public:
    MyCalendarTwo() {
        booked = map<int,int>();
    }
    
    bool book(int start, int end) {
        booked[start]++;
        booked[end]--;
        int count=0;
        for(auto item:booked){
            count+=item.second;
            if(count>=3){
                booked[start]--;
                booked[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */