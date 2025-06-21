
class Solution {
public:
    // 2,2   2,-1  2,-1  2,-6  5,-6  5,-6  5,-6  7,-6
    // 7,-6  7,-6  7,-6  7,-6  7,-5  7,-5  7,-5  7,7
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<pair<int, int>> right(n);
        for (int i = n - 1; i >= 0; i--){
            if(i == n - 1)
                right[i] = {nums[i], nums[i]};
            else
                right[i] = {max(nums[i], right[i + 1].first), 
                            min(nums[i], right[i + 1].second)};
        }
        int max_left = nums[0], min_left = nums[0];
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++){
            max_left = max(max_left, nums[i]);
            min_left = min(min_left, nums[i]);
            int right_ind = i + m - 1;
            if(right_ind < n){
                ans = max(ans, max(1LL * max_left * right[right_ind].first, 1LL * min_left * right[right_ind].second));
            }
        }
        return ans;
    }
};©leetcode
