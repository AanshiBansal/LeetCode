/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        while(original!=NULL || !s1.empty()){
            if(original!=NULL){
                if(original==target)
                    return cloned;
                s1.push(original);
                s2.push(cloned);
                original=original->left;
                cloned=cloned->left;
            }else{
                original=s1.top();
                cloned=s2.top();
                s1.pop();
                s2.pop();
                original=original->right;
                cloned=cloned->right;
            }
        }
        return NULL;
    }
};