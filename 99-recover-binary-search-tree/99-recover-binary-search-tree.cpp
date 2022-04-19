/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        TreeNode* prev=NULL;
        stack<TreeNode*>s;
        while(!s.empty() || root!=NULL){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }else{
                if(prev!=NULL && prev->val>s.top()->val && first==NULL){
                    first=prev;
                }
                if(prev!=NULL && prev->val>s.top()->val && first!=NULL){
                    second=s.top();
                }
                    prev=s.top();
                    s.pop();
                    root=prev->right;
            }
        }
        int temp=first->val;
        cout<<temp<<endl;
        first->val=second->val;
        second->val=temp;
        //swap(first,second);
    }
};