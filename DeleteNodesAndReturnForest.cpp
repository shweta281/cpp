#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode( int val ): val(val), right(nullptr), left(nullptr){}
};

class Solution {
public:
    void asd(TreeNode* root, set<int> &s, vector<TreeNode*>&ans){
        if(root==NULL){
            return;
        }
        if(s.find(root->val)!=s.end() ){
            if(root->left!=NULL){ 
                ans.push_back(root->left);
                asd(root->left, s, ans);
            }
            if( root->right!=NULL){
                ans.push_back(root->right);
                asd(root->right, s, ans);
            }
        }
        else{
            asd(root->right, s,ans);
            asd(root->left,s,ans);
        }
    }
    void link(TreeNode* root, set<int> s){
        if(root==NULL) return;
        // if(s.find(root->val)!=s.end())
        if(root->left!=NULL && s.find(root->left->val)!=s.end() ){ 
            root->left=NULL;
        }
        if(root->right!=NULL && s.find(root->right->val)!=s.end() ){
            root->right=NULL;
        }
        link(root->left, s);
        link(root->right, s);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& t) {
        set<int>s;
        vector<TreeNode*> ans;
        for (int i=0;i<t.size();i++) s.insert(t[i]);
        if(s.find(root->val)==s.end() ){
            ans.push_back(root);
        }
        asd(root, s, ans);
        // return ans;
        for (int i=0; i<ans.size(); i++){
            if(s.find(ans[i]->val)!=s.end()){ 
                // cout<<ans[i]->val<<endl;
                ans.erase(ans.begin()+i, ans.begin()+i+1);
                i--;
                continue;
            }
            link(ans[i], s);
        }
        return ans;
    }
};
void print( TreeNode* t){
    if(t==NULL) return;
    cout<<t->val<<" ";
    print(t->left);
    print(t->right);
    }
int main(){
    TreeNode* root= new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left= new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->right->left= new TreeNode(6);
    root->right->right= new TreeNode(7);
    int arr[]={3,5};
    vector<int>to_delete( arr, arr+ sizeof(arr)/sizeof(arr[0]));
    Solution* s= new Solution();
    vector<TreeNode* >ans = s->delNodes(root, to_delete);
    for ( int i=0; i<ans.size(); i++){
        cout<<"[ ";
        print(ans[i]);
        cout<<"] ";
        }
    }
