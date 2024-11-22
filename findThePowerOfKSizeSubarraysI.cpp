class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int last_p = -1;
        int kmax = nums[0];
        int n = nums.size();
        for (int i = 0; i < k - 1; i++){
            if(nums[i] + 1 != nums[i + 1]){
                last_p = i;
            }
            kmax = nums[i + 1];
        }
        vector<int> ans;
        ans.push_back(last_p == -1? kmax : -1);
        for (int i = k; i < n; i++){
            if(nums[i - 1] + 1 != nums[i]){
                last_p = i - 1;
            }
            kmax = nums[i];
            ans.push_back(last_p < i - k + 1? kmax : -1);
        }
        // ans.push_back(last_p < n - k? kmax : -1);
        // cout<<kmax<<" "<<last_p<<endl;
        return ans;
    }
};
