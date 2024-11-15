class Solution {
public:
    bool isPossible(vector<int>& quan, int m, int mid, int n){
        int count = 0;
        // int kmid = (float)mid;
        // cout<<mid<<endl;
        for (int i = 0; i < m; i++){
            count += ceil((float)quan[i]/mid);
            // cout<<count<<" ";
            if(count > n){
                cout<<endl;
                return false;
            }
        }
        // cout<<endl;
        if(count <= n){
            return true;
        } else {
            return false;
        } 
    }
    int minimizedMaximum(int n, vector<int>& quan) {
        int m = quan.size();
        int start = 1;
        int end = *max_element(quan.begin(), quan.end());
        int ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isPossible(quan, m, mid, n)) { // ispossible true
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
