class Solution {
public:
// 15 - 6*4
// 15 - 2*4
// 15 - 3*4
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int prev=0;
        int sum=0;
        for (int i=0; i<n; i++){
            prev+=nums[i]*i;
            sum+=nums[i];
        }
        int ans=prev;
        for (int i=0; i<n-1; i++){
            cout<<prev<<endl;
            prev+=sum-(nums[n-i-1]*n);
            ans=max(ans, prev);
        }
        return ans;
    }
};
