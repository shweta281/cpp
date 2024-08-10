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
    struct kal{
        TreeNode* root;
        int lair;
        int lev;
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>>map;
        queue<kal>q;
        q.push({root, 0, 0});
        int kmin=0;
        int kmax=0;
        while(!q.empty()){
            TreeNode* node=q.front().root;
            int layer=q.front().lair;
            int level= q.front().lev;
            kmin=min(kmin, layer);
            kmax=max(kmax, layer);
            q.pop();
            map[layer][level].push_back(node->val);
            if(node->left){
                q.push({node->left, layer-1, level+1});
            }
            if(node->right){
                q.push({node->right, layer+1, level+1});
            }
        }
        vector<vector<int>>ans;
        for (auto x: map){
            vector<int>temp;
            for (auto y: x.second){
                sort(y.second.begin(), y.second.end());
                for (auto z: y.second){
                    temp.push_back(z);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
