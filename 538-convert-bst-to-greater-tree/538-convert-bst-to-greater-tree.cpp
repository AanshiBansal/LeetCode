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
private:
    int fn(TreeNode* root, int top){
        if(root==NULL)
            return 0;
        int right=fn(root->right,top);
        int left=fn(root->left,root->val+top+right);
        root->val+=top+right;
        return root->val+left-top;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        fn(root,0);
        return root;
    }
};