class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), count = 0;
        long long rsum = 0, lsum = 0;
        for (int i = 0; i < n; i++){
            rsum += nums[i];
        }
        for (int i = 0; i < n - 1; i++){
            lsum += nums[i];
            rsum -= nums[i];
            if(lsum >= rsum){
                count++;
            }
        }
        return count;
    }
};
