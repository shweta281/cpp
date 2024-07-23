class Solution {
public:
    bool asd(vector<int>&nums, int i, vector<int>&dp){
        if(i==nums.size()-1) return true;
        if(i>=nums.size()) return false;
        if(nums[i]==0) return false;
        if(dp[i]!=-1) return dp[i];
        for (int j=i+1; j<=i+nums[i]; j++){
            if(j<nums.size() && asd(nums, j, dp))
                return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return asd(nums, 0, dp);
    }
};
