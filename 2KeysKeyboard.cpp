#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int helper(int n, int prev, int curr, std::vector<std::vector<int>>& dp) {
        if (n == curr) return 0;
        if (n < curr) return INT_MAX;
        if (dp[prev][curr] != -1) return dp[prev][curr];
        
        int double_op = helper(n, curr, curr * 2, dp);
        int add_op = helper(n, prev, curr + prev, dp);

        if (double_op != INT_MAX) double_op += 2;
        if (add_op != INT_MAX) add_op += 1;

        dp[prev][curr] = std::min(double_op, add_op);
        return dp[prev][curr];
    }

    int minSteps(int n) {
        if (n == 1) return 0;
        if (n == 2) return 2;

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1));

        return helper(n, 1, 2, dp) + 2;
    }
};
