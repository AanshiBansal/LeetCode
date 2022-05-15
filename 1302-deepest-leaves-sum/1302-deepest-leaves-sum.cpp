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
    void inorder(TreeNode* root, int curr, int &depth){
        if(root == NULL){
            depth=max(depth,curr);
            return;
        }
        inorder(root->left,curr+1,depth);
        inorder(root->right,curr+1,depth);
    }
    void helper(TreeNode* root, int curr,int depth, int &ans){
        if(root == NULL){
            return;
        }
        if(curr==depth)
            ans+=root->val;
        helper(root->left,curr+1,depth,ans);
        helper(root->right,curr+1,depth,ans);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth=0;
        inorder(root,0,depth);
        int ans=0;
        helper(root,1,depth,ans);
        return ans;
    }
};