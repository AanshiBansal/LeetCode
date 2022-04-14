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
typedef pair<int,ListNode*> pr;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode();
        ListNode* curr=ans;
        priority_queue<pr,vector<pr>,greater<pr>>pq;
        for(auto list: lists){
            if(list!=NULL){
                pq.push({list->val,list});
            }
        }
        while(!pq.empty()){
            curr->next=pq.top().second;
            pq.pop();
            curr=curr->next;
            if(curr->next){
                pq.push({curr->next->val,curr->next});
            }
        }
        return ans->next;
    }
};