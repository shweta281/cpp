class Solution {
public:
    // 1 :2
    // 1,2,3 :2
    // 1
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(items.begin(), items.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] > b[1]; });
        sort(items.begin(), items.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        // sort(queries.begin(), queries.end());
        
        int m = queries.size(), n = items.size();
        vector<int> maxBeauty(n);
        maxBeauty[0] = items[0][1];
        
        for (int i = 1; i < n; i++) {
            maxBeauty[i] = max(maxBeauty[i - 1], items[i][1]);
        }
        for (int i = 0; i < m; i++) {
            int it = upper_bound(
                items.begin(), items.end(), vector<int>{queries[i] , 0},
                [](const vector<int>& a, const vector<int>& b) {
                    return a[0] < b[0];
                }) - items.begin();
            // cout<<it<<endl;
            if(it - 1 >= 0)
            queries[i] = maxBeauty[it - 1];
            else queries[i] = 0;
            // cout << it << endl;
        }

        return queries;
    }
};
