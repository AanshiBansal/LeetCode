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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
        if(root==NULL)
            return ans;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                if(!q.empty())
                    q.push(NULL);
            }else{
                if(q.front()==NULL)
                    ans.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
        }
        return ans;
    }
};