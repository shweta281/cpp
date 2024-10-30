class Solution {
public:
    void print(vector<int>& arr) {
        for (auto x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int ans = 1000;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int left_dels = 0;
            int right_dels = 0;
            // int n = nums.size();
            vector<int> temp1;
            temp1.push_back(nums[i] * (-1));
            for (int j = i - 1; j >= 0; j--) {
                if ((nums[j] * (-1)) > temp1.back()) {
                    temp1.push_back(nums[j] * (-1));
                } else {
                    int low = lower_bound(temp1.begin(), temp1.end(),
                                          nums[j] * (-1)) -
                              temp1.begin();
                    if (low != 0) {
                        temp1[low] = nums[j] * (-1);
                    }
                }
                // cout<<nums[j]<<" ";
            }
            // cout<<endl;
            vector<int> temp2;
            temp2.push_back(nums[i] * (-1));
            for (int k = i + 1; k < n; k++) {
                if ((nums[k] * (-1)) > temp2.back()) {
                    temp2.push_back(nums[k] * (-1));
                } else {
                    int low = lower_bound(temp2.begin(), temp2.end(),
                                          nums[k] * (-1)) -
                              temp2.begin();
                    if (low != 0) {
                        temp2[low] = nums[k] * (-1);
                    }
                }

                // cout<<nums[j]<<" ";
            }

            // ans = min(ans, (n - temp1.size() - temp2.size()));
            if ((n - temp1.size() - temp2.size() + 1) < ans &&
                temp1.size() != 1 && temp2.size() != 1) {
                print(temp1);
                cout << " ";
                print(temp2);
                ans = n - temp1.size() - temp2.size() + 1;
            }
        }
        return ans;
    }
};
