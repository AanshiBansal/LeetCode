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
// typedef pair<int,ListNode*> pr;
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode* ans = new ListNode();
//         ListNode* curr=ans;
//         priority_queue<pr,vector<pr>,greater<pr>>pq;
//         for(auto list: lists){
//             if(list!=NULL){
//                 pq.push({list->val,list});
//             }
//         }
//         while(!pq.empty()){
//             curr->next=pq.top().second;
//             pq.pop();
//             curr=curr->next;
//             if(curr->next){
//                 pq.push({curr->next->val,curr->next});
//             }
//         }
//         return ans->next;
//     }
// };

class Solution {
private:
    ListNode* merge2Lists(ListNode* first, ListNode* second){
        ListNode* head= new ListNode();
        ListNode * curr=head;
        while(first && second){
            if(first->val<second->val){
                curr->next=first;
                first=first->next;
            }else{
                curr->next=second;
                second=second->next;
            }
            curr=curr->next;
        }
        if(first)
            curr->next=first;
        else
            curr->next=second;
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
            return NULL;
        int gap=1;
        while(gap<n){
            for(int i=0;i<n;i+=(2*gap)){
                if(i+gap<n)
                    lists[i]=merge2Lists(lists[i],lists[i+gap]);
            }
            gap*=2;
        }
        return lists[0];
    }
};