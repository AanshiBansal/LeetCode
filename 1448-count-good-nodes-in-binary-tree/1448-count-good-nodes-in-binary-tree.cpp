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
    int fn(TreeNode* root, int maxi){
        if(root==NULL)
            return 0;
        int ans=0;
        if(maxi<=root->val)
            ans++;
        maxi=max(maxi,root->val);
        return ans+fn(root->left,maxi)+fn(root->right,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        return fn(root,INT_MIN);
    }
};