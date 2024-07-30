// User function template for C++

class Solution {
  public:
  
    void asd( vector<vector<int>>mat, int i, int j, string s, vector<string>&ans){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]==0){
            return ;
        }
        if(i==mat.size()-1 && j==mat[0].size()-1){
            ans.push_back(s);
        }
        mat[i][j]=0;
        asd(mat, i-1, j, s+'U', ans);
        asd(mat, i+1, j, s+'D', ans);
        asd(mat, i, j-1, s+'L', ans);
        asd(mat, i, j+1, s+'R', ans);
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string>ans;
        asd(mat, 0,0, "", ans);
        return ans;
    }
};
