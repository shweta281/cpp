class Solution {
public:
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j){
        if(i<0 || j<0 || i>=dp.size() || j>=dp[0].size()){
            return 0;
        }
        if(dp[i][j]!=0) return dp[i][j];
        int up=1, down=1, left=1, right=1;
        if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j]){
            if(dp[i+1][j]!=0) up+=dp[i+1][j];
            else up=helper(matrix, dp, i+1, j)+1;
        }
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]){
            if(dp[i-1][j]!=0) down+=dp[i-1][j];
            else down=helper(matrix, dp, i-1, j)+1;
        }
        if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j]){
            if(dp[i][j+1]!=0) right+=dp[i][j+1];
            else right=helper(matrix, dp, i, j+1)+1;
        }
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]){
            if(dp[i][j-1]!=0) left+=dp[i][j-1];
            else left=helper(matrix, dp, i, j-1)+1;
        }
        return max(max(up, down), max(left,right));
    }
    // int helper(vector<vector<int>>& matrix, )
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(),0));
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                dp[i][j]=helper(matrix, dp, i, j);
                cout<<dp[i][j]<<" ";
                ans=max(ans, dp[i][j]);
            }
            cout<<endl;
        }
        return ans;
    }
};
