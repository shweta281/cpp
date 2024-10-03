class Solution {
public:
// 0: 1
// 4: 1
// 4: 2
// 4: 3
// 2: 1
// 4: 4
// 0: 2
// 1+3+2+1
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> rem;
        int n=nums.size();
        rem[0]++;
        int presum=0;
        int ans=0;
        for (int i=0; i<n; i++){
            presum+=nums[i];
            int mod=((presum%k)+k)%k;
            rem[mod]++;
            ans+=rem[mod]-1;
        }
        return ans;
    }
};
