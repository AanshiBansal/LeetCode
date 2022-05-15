struct customListNode{
    customListNode* next;
    int start;
    int end;
    customListNode(int l,int r){
        start=l;
        end=r;
        next=NULL;
    };
};
class CountIntervals {
private:
    int counter;
    customListNode* head;
public:
    CountIntervals() {
        counter=0;
        head=new customListNode(0,0);
        head->next=new customListNode(INT_MAX,INT_MAX);
    }
    
    void add(int left, int right) {
        customListNode* prev=head;
        customListNode* curr=head->next;
        while(curr){
            if(curr->start>left || (curr->start==left && curr->end>=right)){
                int l=max(left,prev->end+1);
                int r=min(right,curr->start-1);
                if(l<=r){
                    counter+=(r-l+1);
                    if(l==prev->end-1)
                        prev->end=r;
                    else{
                        prev->next=new customListNode(l,r);
                        prev->next->next=curr;
                    }
                }
                if(right>curr->end){
                    left=curr->end+1;
                }else{
                    break;
                }
            }
            prev=curr;
            curr=curr->next;
        }
    }
    
    int count() {
        return counter;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */