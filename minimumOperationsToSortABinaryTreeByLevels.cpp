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
// 7 6 8 5
// 5 6 7 8

    void swap(vector<int>& arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int minSwaps(vector<int> arr, int N)
    {
        int ans = 0;
        vector<int> temp = arr;
        unordered_map<int, int> h;

        sort(temp.begin(), temp.end());
        for (int i = 0; i < N; i++) {
            h[arr[i]] = i;
        }
        for (int i = 0; i < N; i++) {
            // cout<<arr[i]<<" ";
            if (arr[i] != temp[i]) {
                ans++;
                int init = arr[i];
                swap(arr, i, h[temp[i]]);
                h[init] = h[temp[i]];
                h[temp[i]] = i;
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans += minSwaps(temp, size);
        }
        return ans;
    }
};
