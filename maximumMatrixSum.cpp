class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ksum = 0; 
        int kmin = 100000, count = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                kmin = min(kmin, abs(matrix[i][j]));
                ksum += abs(matrix[i][j]);
                count = matrix[i][j] < 0 ? count + 1 : count;
            }
        }
        return count&1 ? ksum - 2*kmin : ksum;
    }
};
