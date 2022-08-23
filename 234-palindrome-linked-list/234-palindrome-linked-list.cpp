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
    ListNode* halfLinkedList(ListNode* head){
        ListNode* prev=new ListNode();
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        };
        prev->next=NULL;
        return slow;
    }
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=new ListNode();
        ListNode* next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* mid=halfLinkedList(head);
        mid=reverseLinkedList(mid);
        ListNode* first=head;
        ListNode* second=mid;
        bool ans=true;
        while(first){
            if(first->val!=second->val){
                ans=false;
                break;
            }
            first=first->next;
            second=second->next;
        }
        mid=reverseLinkedList(mid);
        ListNode* curr=head;
        ListNode* prev=new ListNode();
        while(curr){
            prev=curr;
            curr=curr->next;
        }
        prev->next=mid;
        return ans;
    }
};