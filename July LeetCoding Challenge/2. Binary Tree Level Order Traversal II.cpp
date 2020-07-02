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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> >sol;
        if(root==NULL)
            return sol;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>ans;
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                sol.push_back(ans);
                ans.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                ans.push_back(front->val);
                if(front->left)
                q.push(front->left);
                if(front->right)
                q.push(front->right);
            }
        }
        reverse(sol.begin(),sol.end());
        return sol;
    }
};
