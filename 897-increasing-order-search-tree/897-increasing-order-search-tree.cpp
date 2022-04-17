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
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        TreeNode*ans=new TreeNode();
        TreeNode*curr=ans;
        stack<TreeNode*>s;
        while(!s.empty() || root!=NULL){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }else{
                curr->right=s.top();
                s.pop();
                curr=curr->right;
                curr->left=NULL;
                if(curr->right){
                    root=curr->right;
                }
            }
            
        }
        return ans->right;
    }
};