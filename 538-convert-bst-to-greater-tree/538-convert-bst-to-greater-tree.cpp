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
        int ans=root->val;
        int right=fn(root->right,top);
        root->val+=right+top;
        int left=fn(root->left,root->val);
        return ans+right+left;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        fn(root,0);
        return root;
    }
};