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
    vector<int>inorder;
    int itr;
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*>s;
        while(!s.empty() || root!=NULL){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }else{
                inorder.push_back(s.top()->val);
                root=s.top()->right;
                s.pop();
            }
        }
        itr=-1;
    }
    
    bool hasNext() {
        return (itr!=inorder.size()-1);
    }
    
    int next() {
        return inorder[++itr];
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */