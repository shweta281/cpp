/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        Node* temp = root;
        q.push(temp);

        while (!q.empty()) {
            int size = q.size();
            Node* node1 = q.front();
            q.pop();
            if(node1==nullptr){
                continue;
            }
            if (node1->left!=nullptr) {
                q.push(node1->left);
                q.push(node1->right);
            }
            for (int i = 0; i < size - 1; i++) {
                Node* node2 = q.front();
                q.pop();
                node1->next = node2;
                node1 = node2;
                if (node2->left!=nullptr) {
                    q.push(node2->left);
                    q.push(node2->right);
                }
            }
        }
        return root;
    }
};
