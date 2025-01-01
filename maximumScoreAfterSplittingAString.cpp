class Solution {
public:
    int maxScore(string s) {
        int one = 0, zero = 0, n = s.length(), ans = INT_MIN;
        for (int i = 0; i < n; i++){
            one += s[i] - '0';
        }
        for (int i = 0; i < n - 1; i++){
            one -= s[i] - '0';
            zero += '1' - s[i];
            ans = max(ans, one + zero);
        }
        return ans;
    }
};
