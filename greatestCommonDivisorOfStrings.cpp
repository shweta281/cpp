class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        string temp = "";
        string ans = "";
        for (int i = 0; i < n; i++){
            temp = temp + str1[i];
            
            if(n % (i + 1) != 0 || m % (i + 1) != 0){
                continue;
            }
            bool flag = true;
            for (int j = i + 1; j < n; j += (i + 1)){
                if(temp != str1.substr(j, i + 1)){
                    flag = false;
                    break;
                }
                // cout<<temp<<" "<<str1.substr(j, i + 1)<<endl;
            }
            if(!flag){
                continue;
            }
            for (int j = 0; j < m; j += (i + 1)){
                if(temp != str2.substr(j, i + 1)){
                    flag = false;
                    break;
                }
                // cout<<str2.substr(j, i + 1)<<endl;
            }
            if(!flag){
                continue;
            }
            ans = temp;
        }
        return ans;
    }
};
