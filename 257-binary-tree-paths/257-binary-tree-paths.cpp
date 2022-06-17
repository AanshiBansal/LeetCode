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
    void fn(TreeNode* root, vector<int>&curr, vector<string>&ans){
        if(root->left==NULL && root->right==NULL){
            curr.push_back(root->val);
            string s="";
            for(int i=0;i<curr.size();i++){
                s+=to_string(curr[i])+"->";
            }
            s.pop_back();
            s.pop_back();
            ans.push_back(s);
            curr.pop_back();
            return;
        }
        curr.push_back(root->val);
        if(root->left!=NULL)
            fn(root->left,curr,ans);
        if(root->right!=NULL)
            fn(root->right,curr,ans);
        curr.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        vector<int>curr;
        if(root==NULL)
            return ans;
        fn(root,curr,ans);
        return ans;
    }
};