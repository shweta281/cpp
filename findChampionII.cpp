class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);
        int m = edges.size();
        for (int i = 0; i < m; i++){
            indeg[edges[i][1]]++;
        }
        int ans = -1;
        for (int i = 0; i < n; i++){
            if(indeg[i] == 0){
                if(ans != -1){
                    return -1;
                }
                ans = i;
            }
        }
        return ans;
    }
};
