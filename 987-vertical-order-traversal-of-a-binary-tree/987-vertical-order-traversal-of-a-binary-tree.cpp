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
        // Usage of multiset
        // multi is used because there can be multiple entries with same value on the same row
        // multimap cannot be used in place of multiset because multimap does not store values in sorted fashion instead stores in the order they are inserted
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