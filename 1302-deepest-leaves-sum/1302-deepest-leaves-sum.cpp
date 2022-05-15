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
    void inorder(TreeNode* root, int curr, int &maxDepth, int &ans){
        if(root == NULL){
            return;
        }
        if(curr>maxDepth){
            ans=0;
            maxDepth=curr;
        }
        if(curr==maxDepth){
            ans+=root->val;
        }
        inorder(root->left,curr+1,maxDepth,ans);
        inorder(root->right,curr+1,maxDepth,ans);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth=0;
        int ans=0;
        inorder(root,0,maxDepth,ans);
        return ans;
    }
};