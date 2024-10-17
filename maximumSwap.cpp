class Solution {
public:
    int maximumSwap(int nums) {
        vector<int> temp;
        int number = nums;
        while(number > 0){
            temp.push_back(number % 10);
            number/=10;
        }
        int n = temp.size();
        for (int i = n - 1; i >= 0; i--){
            int kmax = temp[i];
            int kmax_index = i;
            for (int j = i - 1; j >= 0; j--){
                if(temp[j] >= kmax){
                    kmax = temp[j];
                    kmax_index = j;
                }
            }
            if(kmax != temp[i]){
                int t = temp[i];
                temp[i] = kmax;
                temp[kmax_index] = t;
                break;
            }
        }
        int ans = temp[n - 1];
        for (int i = n - 2; i >= 0; i--){
            ans *= 10;
            ans+=temp[i];
        }
        return ans;
    }
};
