class TrieNode {
public:
    // vector< TrieNode*> node;
    unordered_map<int, TrieNode* > node;
    int red;
    TrieNode() : red(0) {}
};

void insert(string &s, int i, TrieNode* root){
    if(i>=s.length()) return;
    int c=s[i]-'a';
    // cout<<s<<" "<<root->red<<endl;
    if(!root->node[c]){
        TrieNode* new_node= new TrieNode();
        root->node[c]=new_node;
        new_node->red++;
        insert(s, i+1, new_node);
    } else {
        root->node[c]->red++;
        insert(s, i+1, root->node[c]);
    }
}

int search(string &s, int i, TrieNode* root){
    if(i>=s.length()) return 0;
    if(!root) return 0;
    int c=s[i]-'a';
    return search(s, i+1, root->node[c])+root->node[c]->red;
}

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        TrieNode* root=new TrieNode();
        // insert()
        for (int i=0; i<n; i++){
            TrieNode* temp=root;
            insert(words[i], 0, temp);
        }
        vector<int> ans;
        for (int i=0; i<n; i++){
            TrieNode* temp=root;
            ans.push_back(search(words[i], 0, temp));
        }
        return ans;
    }
};
