class Solution {
public:
// 2 3 4 6 8 16
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++){
            map[nums[i]]++;
        }
        int ans = -1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++){
            long long curr_num = nums[i];
            int length = 0;
            while(map.find(curr_num)!=map.end() && map[curr_num] > 0){
                map[curr_num]--;
                curr_num *= curr_num;
                length++;
            }
            length = length < 2 ? -1 : length;
            ans = max(ans, length);
        }
        return ans;
    }
};
