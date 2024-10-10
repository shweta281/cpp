class dsu{
public:
    vector<int> parent;
    vector<int> rank;
    dsu() : parent(vector<int>(26, -1)), rank(vector<int>(26, 1)) {}
    int search(int u){
        if(parent[u] == -1){
            return u;
        }
        return search(parent[u]);
    }
    void unioning(int u, int v){
        int parent_u = search(u);
        int parent_v = search(v);
        if(parent_u != parent_v){
            if(rank[parent_u] < rank[parent_v]){
                parent[parent_u] = parent_v;
                rank[parent_u] += rank[parent_v];
            } else {
                parent[parent_v] = parent_u;
                rank[parent_v] += rank[parent_u];
            }
        } 
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        sort(equations.begin(), equations.end(), [](string &a, string &b){
            return a[1]>b[1];
        });
        // for (auto x: equations){
        //     cout<<x<<endl;
        // }
        dsu *graph = new dsu();
        for (auto x : equations){
            char check = x[1];
            int u = x[0] - 'a';
            int v = x[3] - 'a';
            if(check == '='){
                // cout<<u<<" "<<v<<endl;
                graph->unioning(u, v);
            } else {
                if(graph->search(u) == graph->search(v)){
                    return false;
                }
            }
        }
        return 1;
    }
};
