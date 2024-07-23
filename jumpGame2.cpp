class Solution {
public:
    int asd(vector<int>&nums, int i, vector<int>&dp){
        if(i==nums.size()-1) return 0;
        if(i>=nums.size()) return 10000;
        if(nums[i]==0) return 10000;
        if(dp[i]!=-1) return dp[i];
        // cout<<i<<endl;
        int ans=10000;
        for (int j=i+1; j<=i+nums[i]; j++){
            ans=min(ans, asd(nums, j,dp)+1);

        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return asd(nums, 0,dp);
    }
};
