class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = size(nums);
        vector<int> arr(n, 0);
        arr[0] = 1;
        for (int i = 0; i < n; i++){
            if(arr[i] == 0){
                continue;
            }
            for (int j = i + 1; j < n; j++){
                if(abs(nums[i] - nums[j]) <= target){
                    arr[j] = max(arr[j], arr[i] + 1);
                }
            }
        }
        return arr[n - 1] == 0 ? -1: arr[n - 1] - 1;
    }
};
