//Only one node is given and you have to delete that node from linked list it belongs to 
void deleteNode(ListNode* node) {
    *node=*node->next;
}
