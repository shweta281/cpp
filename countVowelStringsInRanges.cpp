class Solution {
public:
// 1 5 3 0 6
// 1 6 9 9 15
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = queries.size(), m = words.size();
        vector<int> is(m, 0);
        for (int i = 0; i < m; i++){
            char front = words[i][0], back = words[i][words[i].length() - 1];
            int curr = (front == 'a' || front == 'e' || front == 'i'
                        || front == 'o' || front == 'u') && 
                        (back == 'a' || back == 'e'  || back == 'i'||
                         back == 'o' || back == 'u');
            is[i] = i == 0 ? curr : is[i - 1] + curr;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            int l = queries[i][0] - 1, r = queries[i][1];
            ans[i] = l == -1 ? is[r] : is[r] - is[l];
        }
        return ans;
    }
};
