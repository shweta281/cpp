class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int kmin = -50000, ans = INT_MIN;
        int n = values.size();
        for (int i = 0; i < n; i++){
            kmin--;
            ans = max(ans, kmin + values[i]);
            kmin = max(kmin, values[i]);
        }
        return ans;
    }
};
