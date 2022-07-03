/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void rec(Node* root, vector<int>&ans){
        if(root==NULL)
            return;
        ans.push_back(root->val);
        for(auto child:root->children){
            rec(child,ans);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int>ans;
        rec(root,ans);
        return ans;
    }
};