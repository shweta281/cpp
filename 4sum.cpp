class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return {};
        // int a=nums[0],b=nums[1], c=nums[2], d=nums[3];
        sort(nums.begin(), nums.end());
        set<vector<int>>ans;
        for (int i=0;i<nums.size()-3;i++){
            for (int j=i+1; j<nums.size()-2;j++){
                for (int k=j+1;k<nums.size()-1;k++){
                    for (int l=k+1;l<nums.size();l++){
                        // cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
                        if((long)nums[i]+(long)nums[j]+(long)nums[k]+(long)nums[l]==target){
                            ans.insert({nums[i],nums[j],nums[k],nums[l]});
                            break;
                        }
                    }
                }
            }
        }
        vector<vector<int>>a(ans.begin(), ans.end());
        return a;
    }
};
