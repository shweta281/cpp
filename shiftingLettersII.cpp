class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = shifts.size();
        int m = s.length();
        vector<int> mp(m + 1, 0);
        for (int i = 0; i < n; ++i){
            int l = shifts[i][0];
            int r = shifts[i][1];
            int dir = shifts[i][2];
            if(dir == 0){
                mp[l] -= 1;
                mp[r + 1] += 1;
            } else{
                mp[l] += 1;
                mp[r + 1] -= 1;
            }
        }
        
        for (int i = 0; i < m; ++i){
            int disp = (((s[i] - 'a' + mp[i] + 26) % 26) + 26) % 26;
            mp[i + 1] += mp[i];
            char letter = 'a' + disp;
            s[i] = letter;
        }
        return s;
    }
};
