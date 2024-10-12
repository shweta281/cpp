class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int start = 0;
            while(start < nums[i]){
                if((start | start+1) == nums[i]){
                    ans.push_back(start);
                    break;
                }
                start++;
            }
            if(ans.size() != i+1){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
