class MyCalendar {
public:
    map<int,int>booked;
    MyCalendar() {
        booked = map<int,int>();
    }
    
    bool book(int start, int end) {
        auto itr=booked.lower_bound(start);
        if(itr!=booked.end()){
            if(itr->first<end)
                return false;
        }
        if(itr!=booked.begin()){
            itr--;
            if(itr->second>start)
                return false;
        }
        booked[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */