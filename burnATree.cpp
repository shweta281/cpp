//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<int, Node*>parent;
        queue<Node*>q;
        q.push(root);
        parent[root->data]=nullptr;
        Node* t;
        unordered_map<int, int>vis;
        while(q.empty()!=true){
            Node* curr=q.front();
            q.pop();
            if(curr->data==target){
                t=curr;
            }
            if(curr->left){
                parent[curr->left->data]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right->data]=curr;
                q.push(curr->right);
            }
        }
        int ans=0;
        queue<pair<Node*, int>>que;
        que.push({t, 0});
        vis[target]=1;
        // cout<<vis.size()<<endl;
        while(que.empty()!=true){
            Node* curr= que.front().first;
            int ti=que.front().second;
            que.pop();
            // cout<<ti<<" "<<curr->data<<endl;
            ans=max(ti, ans);
            if(curr->left && vis[curr->left->data]==0){
                vis[curr->left->data]=1;
                que.push({curr->left, ti+1});
            }
            if(curr->right && vis[curr->right->data]==0){
                vis[curr->right->data]=1;
                que.push({curr->right, ti+1});
            }
            if(parent[curr->data]!=nullptr && vis[parent[curr->data]->data]==0){
                vis[parent[curr->data]->data]=1;
                que.push({parent[curr->data], ti+1});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
