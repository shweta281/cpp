class Solution {
public:
    int di[3] = {-1, 0, 1};
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> tab(n, vector<int>(m, 0));
        for (int j = 1; j < m; j++) {
            int flag = 0;
            for (int i = 0; i < n; i++) {
                int new_j = j - 1;
                int new_i = i;
                int curr = 0;
                for (int k = 0; k < 3; k++) {
                    new_i = i + di[k];
                    // cout<<new_j<<" "<<j<<" "<<new_i<<" "<<i<<endl;
                    if (new_i < 0 || new_i >= n) {
                        continue;
                    }
                    // cout<<grid[new_i][new_j]<<" "<<grid[i][j]<<endl;
                    if (grid[new_i][new_j] < grid[i][j]) {
                        // cout << new_i << " " << new_j << "  " << i << " " << j
                        //      << endl;

                        // cout<<end
                        // tab[i][j] = max(tab[new_i][new_j] + 1, tab[i][j]);
                        if(j - 1 != 0 && tab[new_i][new_j] == 0){
                            continue;
                        }
                        curr = max(curr, tab[new_i][new_j] + 1);
                        flag = 1;
                    } 
                }
                tab[i][j] = curr;
                ans = max(ans, tab[i][j]);
            }
            if (!flag && j - 1 == 0) {
                return 0;
            }
            // if(!flag){
            //     tab[i][j] = 0;
            // }
        }
        // for (auto x : tab){
        //     for (auto y : x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};
