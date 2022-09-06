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
    TreeNode* pruneTree(TreeNode* &root) {
        if(root==NULL)
            return root;
        TreeNode* left=pruneTree(root->left);
        TreeNode* right=pruneTree(root->right);
        // if(left==NULL)
        //     root->left=NULL;
        // if(right==NULL)
        //     root->right=NULL;
        if(left==NULL && right==NULL && root->val!=1)
            root= NULL;
        return root;
    }
};