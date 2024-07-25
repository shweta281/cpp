class Solution {
  public:
    void asd(vector<vector<int>>&grid, int i,int j, vector<pair<int,int>>&v, int parenti, int parentj){
        grid[i][j]=0;
        if(j+1<grid[0].size() && grid[i][j+1]==1){
            asd(grid,i,j+1,v,parenti, parentj);
            v.push_back({i-parenti, j+1-parentj});}
        if(j-1>=0 && grid[i][j-1]==1){
            asd(grid,i,j-1,v,parenti, parentj);
            v.push_back({i-parenti, j-1-parentj});}
        if(i+1<grid.size() && grid[i+1][j]==1){
            asd(grid,i+1,j,v,parenti, parentj);
            v.push_back({i+1-parenti, j-parentj});}
        if(i-1<grid.size() && grid[i-1][j]==1){
            asd(grid,i-1,j,v,parenti, parentj);
            v.push_back({i-1-parenti, j-parentj});}
        
    }  
    void print(vector<pair<int,int>>&arr){
        for (int i=0 ; i<arr.size(); i++){
            cout<<arr[i].first<<","<<arr[i].second<<" ";
        }
        cout<<endl;
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>>s;
        for (int i=0;i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    vector<pair<int,int>>v;
                    asd(grid, i, j, v, i, j);
                    // print(v);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};
