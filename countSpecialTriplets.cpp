class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<long long, long long> left, right;
        int n = nums.size();
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--){
            right[nums[i]]++;
        }
        for (int i = 0; i < n; i++){
            right[nums[i]]--;
            long long mult = nums[i] * 2;
            if(left.find(mult) != left.end() && right.find(mult) != right.end())
                ans += ((left[mult] * right[mult]) % 1000000007);
            left[nums[i]]++;
        }
        return ans % 1000000007;
    }
};©leetcode
