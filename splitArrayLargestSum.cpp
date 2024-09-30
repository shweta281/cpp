class Solution {
public:
    bool isPossible(vector<int>& nums, int n, int k, int min_sum){
        int partition = 1;
        int curr_sum = 0;
        for (int i = 0; i < n; i++){
            if(nums[i] > min_sum){
                return false;
            }
            if(nums[i] + curr_sum > min_sum){
                partition++;
                if(partition > k){
                    return false;
                }
                curr_sum = nums[i];
            } else {
                curr_sum += nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n){
            return -1;
        }
        int s = 0, e = 0;
        for (int i = 0; i < n; i++){
            s = max(s, nums[i]);
            e += nums[i];
        }
        int ans=0;
        while (s <= e){
            int mid = s + (e - s) / 2;
            cout<<s<<" "<<e<<" "<<mid<<endl;
            if( isPossible(nums, n, k, mid)){
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
