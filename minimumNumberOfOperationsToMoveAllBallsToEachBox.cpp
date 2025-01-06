class Solution {
public:
    vector<int> minOperations(string boxes) {
        int r = 0, rcount = 0, l = 0, lcount = 0, n = boxes.length();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++){
            ans[i] += r;
            ans[n - i - 1] += l;
            rcount += boxes[i] - '0';
            r += rcount;
            lcount += boxes[n - i - 1] - '0';
            l += lcount;
        }
        return ans;
    }
};
