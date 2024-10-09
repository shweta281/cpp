class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> scack;
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++){
            if(scack.empty()){
                if(s[i] == ')'){
                    ans++;
                } else {
                    scack.push('(');
                }
            } else {
                if(s[i] == '('){
                    scack.push('(');
                } else {
                    scack.pop();
                }
            }
        }
        return ans + scack.size();
    }
};