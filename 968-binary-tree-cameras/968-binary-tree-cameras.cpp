// 0 -> covered
// 1 -> not covered
// 2 -> cover for parent required
class Solution {
private:
    int fn(TreeNode* root, int state, map<pair<TreeNode*,int>,int>&mp){
        if(state==2 && root==NULL)
            return 1;
        if(root==NULL)
            return 0;
        if(mp.find({root,state})!=mp.end())
            return mp[{root,state}];
        int ans=1+fn(root->left,0,mp)+fn(root->right,0,mp);
        if(state==0)
            return mp[{root,state}]=min(ans,fn(root->left,1,mp)+fn(root->right,1,mp));
        if(state==1)
            return mp[{root,state}]=min(ans,min(fn(root->left,1,mp)+fn(root->right,2,mp),fn(root->left,2,mp)+fn(root->right,1,mp)));
        return mp[{root,state}]=ans;
    }
public:
    int minCameraCover(TreeNode* root) {
        map<pair<TreeNode*,int>,int>mp;
        return fn(root,1,mp);
    }
};