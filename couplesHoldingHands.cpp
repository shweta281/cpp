class dsu {
public:
    int n;
    vector<int> parent;
    dsu(int n) : n(n), parent(vector<int>(n, -1)) {}
    int search(int u) {
        if (parent[u] == -1) {
            return u;
        }
        return search(parent[u]);
    }
    bool unioning(int u, int v) {
        int parent_u = search(u);
        int parent_v = search(v);
        if (parent_u != parent_v) {
            parent[parent_v] = parent_u;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        dsu *graph = new dsu(n);
        for (int i = 0; i < n; i+=2){
            int u = row[i];
            int v = row[i+1];
            graph->unioning(u, v);
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            int u = row[i];
            int v = u;
            // int v = row[i+1];
            if(u&1){
                v--;
            } else {
                v++;
            }
            ans += graph->unioning(u, v);
        }
        return ans;
    }
};
