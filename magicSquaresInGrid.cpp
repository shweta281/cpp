class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        //check distinct
        //sum same chk
        if(grid.size()<3 || grid[0].size()<3) return 0;
        int ans=0;
        for (int k=0; k<grid.size()-2; k++){
            for (int m=0; m<grid[0].size()-2; m++){
                unordered_set<int>s={1,2,3,4,5,6,7,8,9};
                for (int i=0; i<3; i++){
                    for (int j=0; j<3; j++){
                        // cout<<grid[k+i][m+j]<<endl;
                        s.erase(grid[k+i][m+j]);
                    }
                }
                int flag=0;
                if(!s.empty()) flag=1;
                int hor1=grid[k][m]+grid[k][m+1]+grid[k][m+2];
                int hor2=grid[k+1][m]+grid[k+1][m+1]+grid[k+1][m+2];
                int hor3=grid[k+2][m]+grid[k+2][m+1]+grid[k+2][m+2];
                int ver1=grid[k][m]+grid[k+1][m]+grid[k+2][m];
                int ver2=grid[k][m+1]+grid[k+1][m+1]+grid[k+2][m+1];
                int ver3=grid[k][m+2]+grid[k+1][m+2]+grid[k+2][m+2];
                int diag1=grid[k][m]+grid[k+1][m+1]+grid[k+2][m+2];
                int diag2=grid[k][m+2]+grid[k+1][m+1]+grid[k+2][m];
                // cout<<hor1<<" "<<hor2<<" "<<hor3<<" "<<ver1<<" "<<ver2<<" "
                    // <<ver3<<" "<<diag1<<" "<<diag2<<endl;
                if(!flag && hor1==hor2 && hor2==hor3 && hor3==ver1 && ver1==ver2 
                    && ver2==ver3 && ver3==diag1 && diag1==diag2 && diag2==hor1) {
                        ans++;
                }
            }
        }
        return ans;
    }
};
