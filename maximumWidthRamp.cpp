class Solution {
public:
// 6 0 8 2 1 5
// 8 8 8 5 5 5
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> greater(n, 0);
        int kmax = 0;
        for (int i = n-1; i >= 0; i--){
            kmax = max(nums[i], kmax);
            greater[i] = kmax;
        }
        int i = 0, j = 0;
        int ans = 0;
        for (int i = 0; i < n; i++){
            while(j < n && greater[j] >= nums[i]){
                ans = max(ans, j - i);
                j++;
            }
        }
        return ans;
    }
};
