class Solution {
public:
    void print(vector<int>& arr){
        for (auto x: arr) cout<<x<<" ";
        cout<<endl;
    }
    int longestMonotonicSubsequence(vector<int>& nums) {
        vector<int> inc;
        vector<int> dec;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int s1 = inc.size() - 1;
            int s2 = dec.size() - 1;
            while(s1 >= 0 && inc[s1] >= nums[i]){
                s1--;
            }
            s1++;
            if(s1 == inc.size()){
                inc.push_back(nums[i]);
            } else{
                inc[s1] = nums[i];
            }
            while(s2 >= 0 && dec[s2] <= nums[i]){
                s2--;
            }
            s2++;
            if(s2 == dec.size()){
                dec.push_back(nums[i]);
            } else{
                dec[s2] = nums[i];
            }
            print(inc);
            print(dec);
        }
        return max(inc.size(), dec.size());
    }
};
