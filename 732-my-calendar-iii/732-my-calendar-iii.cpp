class MyCalendarThree {
private:
    map<int,int>booking;
public:
    MyCalendarThree() {
        booking=map<int,int>();
    }
    
    int book(int start, int end) {
        booking[start]++;
        booking[end]--;
        int maxi=0;
        int curr=0;
        for(auto day:booking){
            curr+=day.second;
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */