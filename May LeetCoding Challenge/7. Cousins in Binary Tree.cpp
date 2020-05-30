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
    void util (TreeNode* root, int depth, int parent, int x, int y, int &px, int &py, int &hx, int &hy){
        if(root == NULL)
            return;
        if(root->val==x){
            px=parent;
            hx=depth;
        }
        if(root->val==y){
            py=parent;
            hy=depth;
        }
        util(root->left, depth+1, root->val,x,y,px,py,hx,hy);
        util(root->right, depth+1, root->val,x,y,px,py,hx,hy);
        return;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int px;
        int py;
        int hx;
        int hy;
        util(root,0,0,x,y,px,py,hx,hy);
        if(px!=py && hx==hy)
            return true;
        return false;
    }
};
