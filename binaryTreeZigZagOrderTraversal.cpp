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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        deque<TreeNode*>q;
        int level=0;
        q.push_back(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>temp;
            if(!(level&1)){
                for (int i=0; i<size; i++){
                    TreeNode* top=q.front();
                    // cout<<top->val<<" ";
                    q.pop_front();
                    temp.push_back(top->val);
                    if(top->left)
                        q.push_back(top->left);
                    if(top->right)
                        q.push_back(top->right);
                }
            } else{
                for (int i=0; i<size; i++){
                    TreeNode* top=q.back();
                    // cout<<top->val<<" ";
                    q.pop_back();
                    temp.push_back(top->val);
                    if(top->right){
                        q.push_front(top->right);
                    }
                    if(top->left){
                        q.push_front(top->left);
                    }  
                }
            }
            ans.push_back(temp);
            level++;
            // cout<<endl;
        }
        return ans;
    }
};
