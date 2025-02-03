class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), inc = 1, dec = 1, max_i = 1, max_d = 1;
        for (int i = 0; i < n - 1; i++){
            max_i = max(inc, max_i);
            max_d = max(dec, max_d);
            if(nums[i] >= nums[i + 1]){
                inc = 1;
            } else{
                inc++;
            }
            if(nums[i] <= nums[i + 1]){
                dec = 1;
            } else{
                dec++;
            }
        }
        max_i = max(inc, max_i);
        max_d = max(dec, max_d);
        return max(max_i, max_d);
    }
};
