class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long temp1 = 0LL, temp2 = 0LL;
        for (int i = 0; i < n; i++){
            temp1 += grid[0][i];
        }
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++){
            temp1 -= grid[0][i];
            ans = min(ans, max(temp1, temp2));
            temp2 += grid[1][i];
        }
        return ans;
    }
};
