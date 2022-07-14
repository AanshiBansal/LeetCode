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
    TreeNode* fn(vector<int>& preorder,int a, int b, vector<int>& inorder, int x, int y){
        //cout<<a<<" "<<b<<" "<<x<<" "<<y<<endl;
        if(x>y)
            return NULL;
        TreeNode* node= new TreeNode(preorder[a]);
        int index=x;
        while(inorder[index]!=preorder[a]){
            index++;
        }
        int leftsize=index-a;
        node->left=fn(preorder,a+1,a+index-x,inorder,x,index-1);
        node->right=fn(preorder,a+index-x+1,b,inorder,index+1,y);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return fn(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};