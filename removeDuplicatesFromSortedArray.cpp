class Solution {
public:
    // 0 0 1 1 1 2 2 3 3 4
    // i = 0, j = 0
    // 0 1 0 1
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        while (i < n && j < n) {
            while (j < n && nums[j] <= nums[i]) {
                j++;
            }
            i++;
            if (j == n) {
                break;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        return i;
    }
};
