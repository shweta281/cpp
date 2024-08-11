class Solution {
public:
    //only 0, 1, or 2 deletions are possible to make the soln
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || 
                vis[i][j]==1){
                    return ;
                }
        vis[i][j]=1;
        dfs(grid, vis, i+1, j);
        dfs(grid, vis, i-1, j);
        dfs(grid, vis, i, j+1);
        dfs(grid, vis, i, j-1);
    }
    int count_comp(vector<vector<int>>&grid){
        int comps=0;
        vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    comps++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return comps;
    }
    int minDays(vector<vector<int>>& grid) {
        int comps=count_comp(grid);
        //for 0 deletions
        if(comps!=1) return 0;
        comps=0;
        //for 1 deletions
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    comps=count_comp(grid);
                    grid[i][j]=1;
                    if(comps!=1) return 1;
                }
            }
        }
        //for 2 deletions
        return 2;
    }
};
