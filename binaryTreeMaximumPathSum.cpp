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
    int ans;
    int helper(TreeNode* root){
        if(!root){
            return INT_MIN;
        }
        int left_sum=0, right_sum=0;
        left_sum+=helper(root->left);
        ans=max(ans, left_sum);
        if(left_sum==INT_MIN){
            left_sum=0;
        }
        right_sum+=helper(root->right);
        ans=max(ans, right_sum);
        if(right_sum==INT_MIN){
            right_sum=0;
        }
        // if(left_sum<0){
        //     left_sum=0;
        // }
        // if(right_sum<0){
        //     right_sum=0;
        // }
        int sum=max(left_sum, right_sum)+root->val;
        ans=max(ans, right_sum+left_sum+root->val);
        if(sum<0){
            return INT_MIN;
        }
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        helper(root);
        return ans;
    }
};
