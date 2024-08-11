/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeparent( TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parents){
        if(!root) return;
        if(root->left){
            parents[root->left]=root;
            makeparent(root->left, parents);
        }
        if(root->right){
            parents[root->right]=root;
            makeparent(root->right, parents);
        }
    }
    void dodist(unordered_set<TreeNode*>&s,TreeNode* target, int k,
    unordered_map<TreeNode*, TreeNode*>&parents,vector<int>&ans){
        if(!target){
            return;
        }
        if(s.find(target)!=s.end()) return;
        s.insert(target);
        cout<<target->val<<endl;
        if(k==0){
            ans.push_back(target->val);
            return;
        }
        if(target->left){
            dodist(s, target->left, k-1, parents, ans);
        }
        if(target->right){
            dodist(s, target->right, k-1, parents, ans);
        }
        if(parents[target] ){
            dodist(s, parents[target], k-1, parents, ans);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>parents;
        //make parents map
        parents[root]=nullptr;
        makeparent(root, parents);
        unordered_set<TreeNode*>s;
        // s.insert(root);
        vector<int>ans;
        dodist(s, target, k,parents, ans);
        return ans;
    }
};
