/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* even= new ListNode();
        ListNode* odd= new ListNode();
        ListNode* ptrEven=even;
        ListNode* ptrOdd=odd;
        while(head){
            even->next=head;
            even=even->next;
            head=head->next;
            odd->next=head;
            odd=odd->next;
            if(head)
                head=head->next;
        }
        even->next=ptrOdd->next;
        return ptrEven->next;
        
    }
};
