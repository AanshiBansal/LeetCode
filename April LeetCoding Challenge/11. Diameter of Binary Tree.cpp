/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int util(TreeNode* root, int &ans){
    if(root == NULL)
        return 0;
    int l=util(root->left,ans);
    int r=util(root->right,ans);
    ans=max(ans,l+r);
    return 1+max(l,r);
}
int diameterOfBinaryTree(TreeNode* root) {
    int ans=0;
    util(root,ans);
    return ans;
}
