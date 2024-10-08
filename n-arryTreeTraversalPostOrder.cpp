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
public:
    vector<int>ans;
    void helper(Node* root){
        if(!root){
            return;
        }
        for (auto x: root->children){
            helper(x);
        }
        ans.push_back(root->val);
        return;
    }
    vector<int> postorder(Node* root) {
        helper(root);
        return ans;
    }
};
