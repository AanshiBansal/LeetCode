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
class BSTIterator {
private:
    stack<TreeNode*>s;
public:
    BSTIterator(TreeNode* root) {
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
    }
    
    bool hasNext() {
        return s.size()>0;
    }
    
    int next() {
        int ans=s.top()->val;
        TreeNode* root=s.top();
        s.pop();
        root=root->right;
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
        return ans;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */