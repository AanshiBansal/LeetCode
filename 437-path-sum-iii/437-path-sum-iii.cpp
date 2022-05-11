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
    void inorder(TreeNode* root, vector<long long>&path, int &ans, int &targetSum){
    path.push_back(0);
    int size=path.size();
    int curr=root->val;
    for(int i=0;i<size;i++){
        path[i]+=curr;
        if(path[i]==targetSum){
            ans++;
        }
    }
    if(root->left !=NULL)
        inorder(root->left, path, ans, targetSum);
    if(root->right !=NULL)
        inorder(root->right,path, ans, targetSum);
    for(int i=0;i<size;i++){
        path[i]-=curr;
    }
    path.pop_back();
}
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        vector<long long>path;
        if(root==NULL)
            return ans;
        inorder(root,path,ans,targetSum);
        return ans;
    }
};