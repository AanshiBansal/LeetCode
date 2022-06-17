// 0 -> covered
// 1 -> not covered
// 2 -> cover for parent required
class Solution {
private:
    int fn(TreeNode* root, int state, vector<unordered_map<TreeNode*,int>>&mp){
        if(state==2 && root==NULL)
            return 1;
        if(root==NULL)
            return 0;
        if(mp[state].find(root)!=mp[state].end())
            return mp[state][root];
        int ans=1+fn(root->left,0,mp)+fn(root->right,0,mp);
        if(state==0)
            return mp[state][root]=min(ans,fn(root->left,1,mp)+fn(root->right,1,mp));
        if(state==1)
            return mp[state][root]=min(ans,min(fn(root->left,1,mp)+fn(root->right,2,mp),fn(root->left,2,mp)+fn(root->right,1,mp)));
        return mp[state][root]=ans;
    }
public:
    int minCameraCover(TreeNode* root) {
        vector<unordered_map<TreeNode*,int>>mp(3);
        return fn(root,1,mp);
    }
};