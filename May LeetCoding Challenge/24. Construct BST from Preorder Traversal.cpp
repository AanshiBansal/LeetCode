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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)
            return NULL;
        stack<TreeNode*>s;
        TreeNode* ans= new TreeNode(preorder[0]);
        s.push(ans);
        for(int i=1;i<preorder.size();i++){
            TreeNode* temp = new TreeNode(preorder[i]);
            if(preorder[i]<s.top()->val){
                s.top()->left=temp;
                s.push(temp);
            }
            else{
                TreeNode* help;
                while(!s.empty()&&s.top()->val<preorder[i]){
                    help=s.top();
                    s.pop();
                }
                help->right=temp;
                s.push(temp);
            }
        }
        return ans;
    }
};
