class Solution {
public:
// 101
// 011
    int count;
    void helper(vector<int>& nums, int n, int i, int oring, int kmax){
        if(i >=  n){
            return;
        }
        int take = oring | nums[i];
        if(take == kmax){
            count++;
        }
        helper(nums, n, i+1, take, kmax);
        helper(nums, n, i+1, oring, kmax);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int kmax = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            kmax = kmax | nums[i];
        }
        count = 0;
        helper(nums, n, 0, 0, kmax);
        return count;
    }
};
