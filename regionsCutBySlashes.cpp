class Solution {
public:
    void dfs(vector<vector<int>>& temp, int i, int j){
        if(i<0 || j<0 || i>=temp.size() || j>=temp[0].size() || temp[i][j]==1)
            return;
        temp[i][j]=1;
        dfs(temp, i-1, j);
        dfs(temp, i+1, j);
        dfs(temp, i, j-1);
        dfs(temp, i, j+1);
    }
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>>temp;
        // int flag=0;
        for (int i=0; i<grid.size(); i++){
            // if(flag==1) flag=0;
            vector<int>top;
            vector<int>mid;
            vector<int>bottom;
            for (int j=0; j<grid[0].length(); j++){
                if(grid[i][j]=='/'){
                    top.push_back(0);
                    top.push_back(0);
                    top.push_back(1);
                    mid.push_back(0);
                    mid.push_back(1);
                    mid.push_back(0);
                    bottom.push_back(1);
                    bottom.push_back(0);
                    bottom.push_back(0);
                }  
                else if(grid[i][j]=='\\' ){
                    top.push_back(1);
                    top.push_back(0);
                    top.push_back(0);
                    mid.push_back(0);
                    mid.push_back(1);
                    mid.push_back(0);
                    bottom.push_back(0);
                    bottom.push_back(0);
                    bottom.push_back(1);
                }
                else{
                    top.push_back(0);
                    top.push_back(0);
                    top.push_back(0);
                    mid.push_back(0);
                    mid.push_back(0);
                    mid.push_back(0);
                    bottom.push_back(0);
                    bottom.push_back(0);
                    bottom.push_back(0);
                }
            }
            temp.push_back(top);
            temp.push_back(mid);
            temp.push_back(bottom);
        }
        for (int i=0; i<temp.size(); i++){
            for (int j=0; j<temp[0].size(); j++){
                cout<<temp[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans=0;
        for (int i=0; i<temp.size(); i++){
            for (int j=0; j<temp[0].size(); j++){
                if(temp[i][j]==0){
                    dfs(temp, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
