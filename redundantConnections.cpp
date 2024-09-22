class union_find{
    public:

    int n;
    vector<int>parent;

    union_find(int n){
        this->n = n;
        this->parent = vector<int>(n,-1);
    }

    int search(int k){
        if(parent[k]==-1) return k;
        // cout<<k<<endl;
        return search(parent[k]);
    }

    bool _union(int u, int v){
        int godfather_u = search(u);
        int godfather_v = search(v);
        if(godfather_u!=godfather_v){
            parent[godfather_u] = godfather_v;
            // cout<<godfather_u<<" "<<godfather_v<<endl;
            return false;
        } else {
            return true;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        union_find* graph = new union_find(n);
        vector<int>ans;

        for (int i=0; i<n; i++){
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;
            // cout<<u<<" "<<v<<endl;
            if (graph->_union(u, v)){
                ans = edges[i];
            }
        }
        return ans;
    }
};
