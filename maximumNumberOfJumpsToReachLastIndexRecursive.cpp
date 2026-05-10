class Solution {
public:

    int helper(vector<int>& nums, int target, int n, int i, vector<int>& arr){
        if(i >= n){
            return INT_MIN;
        }
        if(i == n - 1){
            return 0;
        }
        if(arr[i] != -1){
            return arr[i];
        }
        int steps = 0;
        int kmax = INT_MIN;
        for (int j = i + 1; j < n; j++){
            if(abs(nums[j] - nums[i]) <= target){
                steps = helper(nums, target, n, j, arr) + 1;
                kmax = max(kmax, steps);
            }
        }
        return arr[i] = kmax;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = size(nums);
        vector<int> arr(n, -1);
        int ans = helper(nums, target, n, 0, arr);
        return ans < 0 ? -1 : ans;
    }
};
