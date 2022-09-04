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
        map<pair<int,int>,vector<int>>mp;
        queue<pair<TreeNode*, pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int r=q.front().second.first;
            int c=q.front().second.second;
            TreeNode* node=q.front().first;
            q.pop();
            mp[{r,c}].push_back(node->val);
            if(node->left!=NULL){
                q.push({node->left,{r+1,c-1}});
            }
            if(node->right!=NULL){
                q.push({node->right,{r+1,c+1}});
            }
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            sort(itr->second.begin(),itr->second.end());
        }
        map<int,vector<int>>mp2;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            int c=itr->first.second;
            if(mp2[c].size()==0)
                mp2[c]=itr->second;
            else
                mp2[c].insert(mp2[c].end(),itr->second.begin(),itr->second.end());
        }
        vector<vector<int>>ans;
        for(auto itr=mp2.begin();itr!=mp2.end();itr++){
            ans.push_back(itr->second);
        }
        return ans;
    }
};