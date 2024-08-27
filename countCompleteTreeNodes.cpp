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

    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left=0;
        int right=0;
        TreeNode* templ=root;
        TreeNode* tempr=root;
        while(templ){
            templ=templ->left;
            left++;
        } 
        while(tempr){
            tempr=tempr->right;
            right++;
        }
        // cout<<left<<" "<<right<<endl;
        if(left==right) return pow(2, left)-1;
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};
