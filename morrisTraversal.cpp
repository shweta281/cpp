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
    TreeNode* findpred( TreeNode* node){
        TreeNode* pred=node->left;
        while(pred->right!=nullptr && pred->right!=node) pred=pred->right;
        return pred;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        while(root!=nullptr){
            // cout<<root->val<<endl;
            if(root->left==nullptr){
                ans.push_back(root->val);
                root=root->right;
            }
            else{
                TreeNode* pred= findpred(root);
                if(pred->right==nullptr){
                    pred->right=root;
                    root=root->left;
                }
                else{
                    ans.push_back(root->val);
                    pred->right=nullptr;
                    root=root->right;
                }
            }
        }
        return ans;
    }
};
