class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int kmax=*max_element(nums.begin(), nums.end());
        int length=0, ans=0;
        for (int i=0; i<nums.size(); i++){
            if(nums[i]!=kmax){
                length=0;
            }
            else{
                length++;
                ans=max(ans, length);
            }
        }
        return ans;
    }
};
