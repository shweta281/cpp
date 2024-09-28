class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int t=0;
        // if(nums[0]==0) t=1;
        for (int i=0;i<nums.size();i++){
            // cout<<nums[i]<<" "<<t<<endl;
            if(nums[i]==t){
                ans++;
                t=1-t;
            }
        }
        return ans;
        
        
    }
};
