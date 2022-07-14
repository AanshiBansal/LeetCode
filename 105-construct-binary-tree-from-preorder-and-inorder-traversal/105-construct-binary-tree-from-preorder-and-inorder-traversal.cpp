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
    unordered_map<int,int>mp;
    TreeNode* fn(vector<int>& preorder,int a, int b, int x, int y){
        if(x>y)
            return NULL;
        TreeNode* node= new TreeNode(preorder[a]);
        int index=mp[preorder[a]];
        int leftsize=index-a;
        node->left=fn(preorder,a+1,a+index-x,x,index-1);
        node->right=fn(preorder,a+index-x+1,b,index+1,y);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return fn(preorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};