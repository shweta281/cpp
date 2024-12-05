class Solution {
public:
    bool canChange(string s, string t) {
        int i = 0, j = 0, n = s.length(), m = t.length();
        while (i < n && j < m) {
            if (s[i] == '_') {
                i++;
                continue;
            }
            if (t[j] == '_') {
                j++;
                continue;
            }
            if (s[i] == t[j]) {
                if (s[i] == 'R') {
                    if (i > j) {
                        return false;
                    }
                }
                if (s[i] == 'L') {
                    if (i < j) {
                        return false;
                    }
                }
                i++;
                j++;
            } else {
                return false;
            }
        }
        // cout<<i<<" "<<j<<endl;
        while(i < n){
            if(s[i] != '_'){
                return false;
            }
            i++;
        }
        while(j < m){
            if(t[j] != '_'){
                return false;
            }
            j++;
        }
        return true;
    }
};
