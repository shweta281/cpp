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
    void flatten(TreeNode* root) {
        TreeNode* head=root;
        while(root!=nullptr){
            if(root->left==nullptr){
                root=root->right;
            }
            else{
                TreeNode* pred=root;
                pred=pred->left;
                while(pred->right!=nullptr && pred->right!=root){
                    pred=pred->right;
                }
                pred->right=root->right;
                root->right=root->left;
                TreeNode* temp=root;
                root=root->left;
                temp->left=nullptr;
            }
        }
    }
};
