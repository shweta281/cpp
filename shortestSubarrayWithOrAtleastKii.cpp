class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k == 0){
            return 1;
        }
        int n = nums.size();
        // unordered_map<int, int> mp;
        vector<int> mp(32, 0);
        int o = 0;
        int i = 0;
        int kmin = 1;
        // cout << o << endl;
        while (i < n && o < k) {
            o |= nums[i];
            // cout<<o<<endl;
            int number = nums[i];
            int start = 0;
            while (number > 0) {
                mp[start] += (number % 2);
                start++;
                number /= 2;
            }
            i++;
        }
        if(o < k){
            return -1;
        }
        // if (i == n) {
        //     return o >= k ? n : -1;
        // }
        int j = 0;
        kmin = i;
        // cout<<kmin<<endl;
        // cout<<i<<endl;
        // i--;
        for (; i < n; i++) {
            while (j < i - 1 && o >= k) {
                int window = nums[j];
                int pow = 1;
                int w_start = 0;
                while (window > 0) {
                    mp[w_start] -= (window % 2);
                    if (mp[w_start] == 0 && (window % 2)) {
                        o -= pow;
                    }
                    pow *= 2;
                    w_start++;
                    window /= 2;
                    // cout<<o<<endl;
                }
                j++;
                if (o >= k) {
                    kmin = min(kmin, i - j );
                    // cout<<o<<" "<<kmin<<endl;
                }
            }
            o |= nums[i];
            int number = nums[i];
            int start = 0;
            // cout << o << endl;
            if (o >= k) {
                kmin = min(kmin, i - j + 1);
            }
            while (number > 0) {
                mp[start] += (number % 2);
                start++;
                number /= 2;
            }
        }
        // cout << i << " " << j << " " << o << " " << k << endl;
        i--;
        while (j < i && o >= k) {
            int window = nums[j];
            int pow = 1;
            int w_start = 0;
            while (window > 0) {
                mp[w_start] -= (window % 2);
                if (mp[w_start] == 0 && (window % 2)) {
                    o -= pow;
                }
                pow *= 2;
                w_start++;
                window /= 2;
                // cout<<o<<endl;
            }
            j++;
            if (o >= k) {
                // cout << o << endl;
                kmin = min(kmin, i - j + 1);
            }
            // cout<<o<<endl;
        }
        // cout << i << " " << j << " " << o << " " << k << endl;

        return kmin;
    }
};
