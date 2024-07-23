class Solution {
public:
    bool asd1(vector<int>&nums, int i, vector<int>&vis){
        if(i>=nums.size() || i<0) return false;
        if(nums[i]==0) return true;
        if(vis[i]!=0) return false;
        vis[i]=1;
        return asd1(nums, i+nums[i], vis) || asd1(nums, i-nums[i], vis) ;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(), 0);
        return asd1(arr, start, vis);
    }
};
