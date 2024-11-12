class Solution {
public:
// 4 - 8 = 5 
// 1 - 3
// 0 -> 2
    bool checkPrime(int n){
        if(n == 1) return false;
        for (int i = n/ 2; i >= 2; i-- ){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 1; i > 0; i--){
            int diff = nums[i - 1] - nums[i];
            // cout<<diff<<endl;
            if(diff < 0){
                continue;
            }
            
            int start = diff + 1;
            int end = nums[i - 1] - 1;
            bool flag = false;
            // cout<<start<<" "<<end<<endl;
            while(start <= end){
                if(checkPrime(start)){
                    // cout<<start<<endl;
                    nums[i - 1] = nums[i - 1] - start;
                    flag = true;
                    break;
                }
                start++;
            }
            // cout<<(start)<<endl;
            // cout<<i<<" "<<start<<endl;
            if(!flag){
                return false;
            }
            
        }
        // for (auto x:nums){
        //     cout<<x<<"endl";
        // }
        return 1;
    }
};
