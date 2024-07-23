class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int i=0,p=0,ans =0;
        unordered_map<int,int>m;
        for (int j=0; j<nums.size(); j++){
            if(m.size()>k){
                while(i<j && m.size()>k){
                    m[nums[i]]--;
                    if(m[nums[i]]==0)
                        m.erase(nums[i]);
                    i++;
                }
                p=i;
            }
            if(m.size()==k){
                while(i<j && m[nums[i]]>1){
                    m[nums[i]]--;
                    i++;
                }
                ans+=(i-p)+1;
            }
            m[nums[j]]++;
        }
        if(m.size()>k){
                while(i<nums.size() && m.size()>k){
                    m[nums[i]]--;
                    if(m[nums[i]]==0)
                        m.erase(nums[i]);
                    i++;
                }
                p=i;
            }
        if(m.size()==k){
            while(i<nums.size() && m[nums[i]]>1){
                m[nums[i]]--;
                i++;
            }
            ans+=(i-p)+1;
            }
        return ans;
    }
};
