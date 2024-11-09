class Solution {
public:
    long long minEnd(int n, int x) {
        string num_x = "";
        string num_n = "";
        n--;
        while(n > 0){
            num_n += to_string(n % 2);
            n /= 2;
        }
        // int zero_count = 0;
        while(x > 0){
            // zero_count += 1 - (x % 2);
            num_x += to_string(x % 2);
            x /= 2;
        }
        long long ans = 0;
        long long j = 0;
        long long pow = 1;
        for (int i = 0; i < num_x.length(); i++){
            if(num_x[i] == '0' && j < num_n.length()){
                ans += pow * (num_n[j] - '0');
                j++;
                // if(j >= num_n.length()){
                //     break;
                // }
            } else {
                ans += pow * (num_x[i] - '0');
            }
            pow *= 2;
        }
        while(j < num_n.length()){
            ans += pow * (num_n[j] - '0');
            j++;
            pow *= 2;
        }
        // cout<<num_x<<" "<<num_n<<endl;
        return ans;
    }
};
