class Solution {
public:
// 2 g
// 3 w
// 4 r
// 5 d
// 6 l
// 7 u
// 8 rd
// 9 lu
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        int k = 0;
        k = guards.size();
        for (int i =0; i<k; i++){
            mat[guards[i][0]][guards[i][1]] = 2;
        }
        k = walls.size();
        for (int i =0; i<k; i++){
            mat[walls[i][0]][walls[i][1]] = 3;
        }
        int ans = 0;
        // down right
        for (int i = m - 1; i >= 0; i--){
            for (int j = n - 1; j >= 0; j--){
                if(mat[i][j] == 2 || mat[i][j] == 9){
                    if(i - 1 >= 0 && mat[i - 1][j] != 3 && mat[i - 1][j] != 2){
                        if(mat[i - 1][j] == 6){
                            mat[i - 1][j] = 9;
                        } else{
                            mat[i - 1][j] = 7;
                        }
                    }
                    if(j - 1 >= 0 && mat[i][j - 1] != 3 && mat[i][j - 1] != 2){
                        if(mat[i][j - 1] == 7){
                            mat[i][j - 1] = 9;
                        } else{
                            mat[i][j - 1] = 6;
                        }
                    }
                    continue;
                } else if(mat[i][j] == 3){
                    continue;
                } else if(mat[i][j] == 6){
                    if(j - 1 >= 0 && mat[i][j - 1] != 3 && mat[i][j - 1] != 2){
                        if(mat[i][j - 1] == 7){
                            mat[i][j - 1] = 9;
                        } else{
                            mat[i][j - 1] = 6;
                        }
                    }
                    continue;
                } else if(mat[i][j] == 7){
                    if(i - 1 >= 0 && mat[i - 1][j] != 3 && mat[i - 1][j] != 2){
                        if(mat[i - 1][j] == 6){
                            mat[i - 1][j] = 9;
                        } else{
                            mat[i - 1][j] = 7;
                        }
                    }
                    continue;
                }
            }
        }
        // up left
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(mat[i][j] == 2 || mat[i][j] == 8){
                    if(i + 1 < m && mat[i + 1][j] != 3 && mat[i + 1][j] != 2){
                        if(mat[i+1][j] == 4){
                            mat[i + 1][j] = 8;
                        } else{
                            mat[i + 1][j] = 5;
                        }
                    }
                    if(j + 1 < n && mat[i][j + 1] != 3 && mat[i][j + 1] != 2){
                        if(mat[i][j + 1] == 5){
                            mat[i][j + 1] = 8;
                        } else{
                            mat[i][j + 1] = 4;
                        }
                    }
                    continue;
                } else if(mat[i][j] == 3){
                    continue;
                } else if(mat[i][j] == 4){
                    if(j + 1 < n && mat[i][j + 1] != 3 && mat[i][j + 1] != 2){
                        if(mat[i][j + 1] == 5){
                            mat[i][j + 1] = 8;
                        } else{
                            mat[i][j + 1] = 4;
                        }
                    }
                    continue;
                } else if(mat[i][j] == 5){
                    if(i + 1 < m && mat[i + 1][j] != 3 && mat[i + 1][j] != 2){
                        if(mat[i+1][j] == 4){
                            mat[i + 1][j] = 8;
                        } else{
                            mat[i + 1][j] = 5;
                        }
                    }
                    continue;
                }
                if(mat[i][j] == 0)
                ans++;
            }
        }
        // for (auto x: mat){
        //     for (auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};
