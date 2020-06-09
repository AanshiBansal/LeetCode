ListNode* reverseList(ListNode* head) {
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* next;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
