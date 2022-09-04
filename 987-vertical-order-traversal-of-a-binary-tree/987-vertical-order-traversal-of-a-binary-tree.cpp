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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,multiset<pair<int,int>>>mp;
        queue<pair<TreeNode*, pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            TreeNode* node=q.front().first;
            q.pop();
            mp[c].insert({r,node->val});
            if(node->left!=NULL){
                q.push({node->left,{r+1,c-1}});
            }
            if(node->right!=NULL){
                q.push({node->right,{r+1,c+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto obj:mp){
            vector<int>curr;
            for(auto obj2:obj.second){
                curr.push_back(obj2.second);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};