class Solution {
public:
// 0 1 3 0 4 2 2 2
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0, n = size(nums);
        while(i < n && j < n){
            if(nums[i] == val){
                j = j == 0 ? i : j;
                while(j < n && nums[j] == val){
                    j++;
                }
                if(j == n){
                    break;
                }
                // int temp = nums[i];
                // nums[i] = nums[j];
                // nums[j] = temp;
                nums[i] = nums[i] + nums[j];
                nums[j] = nums[i] - nums[j];
                nums[i] = nums[i] - nums[j];
            } 
            i++;
        }
        return i;
    }
};
