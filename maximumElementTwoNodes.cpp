#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode():data(0),left(nullptr), right(nullptr){}
    TreeNode(int d):data(d), left(nullptr), right(nullptr){}
    TreeNode(int d, TreeNode* l, TreeNode* r): data(d), left(l), right(r){}
    };

void insert(TreeNode* root, int item){
    if(root->left==NULL && item<root->data){
        root->left= new TreeNode(item);
        }
    if(root->right==NULL && item>root->data){
        root->right= new TreeNode(item);
        }
    if(root->data>item) insert(root->left, item);
    if(root->data<item) insert(root->right, item);
    }

void print(TreeNode* root){
    if(root==NULL) return ;
    cout<<root->data<<endl;
    print(root->left);
    print(root->right);
    }

TreeNode* findLCA(TreeNode* root, int p, int q){
        if(root==NULL || root->data==p || root->data==q) return root;
        TreeNode* leftres;
        TreeNode* rightres;
        
        if(p>root->data) leftres=findLCA(root->right, p ,q);
        else leftres=findLCA(root->left, p ,q);
        
        if(q>root->data) rightres=findLCA(root->right, p ,q);
        else rightres=findLCA(root->left, p ,q);
        
        if((leftres->data==p && rightres->data==q) || (leftres->data==q && rightres->data==p)) return root;
        if(leftres->data==p || leftres->data==q) return leftres;
        return rightres;
    }

void maxelement(TreeNode* root, int &kmax, int stop){
    if(root==NULL) return;
    kmax=max(kmax, root->data);
    if(root->data==stop) {
        return;
        }
    if(root->data<stop)
        maxelement(root->right, kmax, stop);
    else
        maxelement(root->left, kmax, stop);
    }

int findMaxElementBetweenNodes(TreeNode* root, int a, int b){
    TreeNode* lca= findLCA(root, a, b);
    int ka=lca->data;
    int kb=ka;
    if(ka!=a)
        maxelement(lca->left,ka , a);
    if(kb!=b)
        maxelement(lca->right, kb, b);
    return max(ka,kb);
    
    }
int main(){
    int arr[]={18, 36, 9, 6, 12, 10, 1, 8};
    int a=1, b=8;
    TreeNode* root= new TreeNode(arr[0]);
    for (int i=1; i<(sizeof(arr)/sizeof(int)); i++){
        insert(root, arr[i]);
        }
    // print(root);
    cout<< findMaxElementBetweenNodes(root, a, b);
    }
