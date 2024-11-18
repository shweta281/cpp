class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int j = n - 1;
        arr.push_back(INT_MAX);
        int ans = n - 1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] <= arr[j]) {
                while (i < j && j - 1 > 0 && (arr[i] <= arr[j - 1]) &&
                       (arr[j - 1]) <= arr[j]) {
                    j--;
                }
            } else {
                while (j < n && arr[i] > arr[j]) {
                    j++;
                }
            }
            ans = min(ans, j - i - 1);
            if (arr[i] > arr[i + 1]) {
                while (j > 0 && arr[j - 1] <= arr[j]) {
                    ans = min(ans, j - 1);
                    j--;
                }
                break;
            }
            if (i >= j) {
                return 0;
            }
        }
        return ans;
    }
};
