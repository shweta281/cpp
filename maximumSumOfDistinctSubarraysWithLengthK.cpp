class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int last_p = -100001;
        unordered_map<int, int> mp;
        long long ksum = 0;
        int kans = 0;
        for (int i = 0; i < k; i++) {
            ksum += nums[i];
            if (mp.find(nums[i]) != mp.end()) {
                last_p = max(last_p, mp[nums[i]]);
            }
            mp[nums[i]] = i;
        }
        if (last_p < -k) {
            kans = max(kans, ksum);
        }
        // cout << kans << endl;
        for (int i = k; i < n; i++) {
            ksum += (nums[i] - nums[i - k]);
            if (mp.find(nums[i]) != mp.end()) {
                last_p = max(last_p, mp[nums[i]]);
            }
            if (last_p < i - k + 1) {
                kans = max(kans, ksum);
            }
            mp[nums[i]] = i;
        }
        return kans;
        // for (int i = 0; i )
    }
};
