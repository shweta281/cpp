class Solution {
public:// 0 1 0 1 1 0 0, 0 1 0 1 1 0 0
    int minSwaps(vector<int>& nums) {
        //count ones
        int ones=0;
        for (int i=0; i<nums.size(); i++){ if( nums[i]==1) ones++;}
        //iterate over the arr with a window size of 'ones' and catch window with max ones
        int onecount=0;
        for (int i=0; i<ones; i++){
            if(nums[i]==1) onecount++;
        }
        int ans=onecount;
        for (int i=ones; i<nums.size()+ones; i++){
            // cout<<onecount<<" "<<i<<endl;
            if(nums[i-ones]==1) onecount--;
            if(nums[i%nums.size()]==1) onecount++;
            ans=max(onecount,ans);
        }
        return ones-ans;
    }
};
