class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long ans = 0;
        // nums.sort();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++){
            int item1 = lower - nums[i]; 
            int item2 = upper - nums[i]; 
            // vector<int> temp(nums.begin() + i + 1, nums.end());
            // sort(temp.begin(), temp.end());
            int lbound = lower_bound(nums.begin() + i + 1,nums.end(),
                                    item1) - nums.begin();
            int ubound = upper_bound(nums.begin() + i + 1,nums.end(),
                                    item2) - nums.begin();
            ans += ubound - lbound; 
            // cout<<nums[i]<<" "<<lbound<<" "<<ubound<<endl;
        }
        return ans;
    }
};
