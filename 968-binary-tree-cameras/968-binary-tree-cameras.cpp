// 0 -> covered
// 1 -> not covered
// 2 -> cover for parent required
class Solution {
private:
    vector<unordered_map<TreeNode*,int>>mp;
    int fn(TreeNode* root, int state){
        if(state==2 && root==NULL)
            return 1;
        if(root==NULL)
            return 0;
        if(mp[state].find(root)!=mp[state].end())
            return mp[state][root];
        int ans=1+fn(root->left,0)+fn(root->right,0);
        if(state==0)
            return mp[state][root]=min(ans,fn(root->left,1)+fn(root->right,1));
        if(state==1)
            return mp[state][root]=min(ans,min(fn(root->left,1)+fn(root->right,2),fn(root->left,2)+fn(root->right,1)));
        return mp[state][root]=ans;
    }
public:
    int minCameraCover(TreeNode* root) {
        mp=vector<unordered_map<TreeNode*,int>>(3);
        return fn(root,1);
    }
};