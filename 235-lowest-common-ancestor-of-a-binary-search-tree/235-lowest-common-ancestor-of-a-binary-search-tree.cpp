/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(p->val>q->val)
//             return lowestCommonAncestor(root,q,p);
//         if(p->val<=root->val && q->val>=root->val)
//             return root;
//         if(p->val<root->val && q->val<root->val)
//             return lowestCommonAncestor(root->left,p,q);
//         else
//             return lowestCommonAncestor(root->right,p,q);
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val)
            return lowestCommonAncestor(root,q,p);
        while(!(p->val<=root->val && q->val>=root->val)){
            if(q->val<root->val)
                root=root->left;
            else
                root=root->right;
        }
        return root;
    }
};