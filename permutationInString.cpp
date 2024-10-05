
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int, int> dict1;
        unordered_map<int, int> dict2;
        for (int i = 0; i < 26; i++){
            dict1[i]=0;
            dict2[i]=0;
        }
        int n = s1.length();
        int m = s2.length();
        if( n > m) return false;
        for (int i = 0; i < n; i++){
            dict1[s1[i] - 'a']++;
        }
        for (int i = 0; i < n; i++){
            dict2[s2[i] - 'a']++;
        }
        for (int i = n; i < m; i++){
            if( dict1 == dict2){
                return true;
            }
            dict2[s2[i-n] - 'a']--;
            dict2[s2[i] - 'a']++;
        }
        if( dict1 == dict2 ){
            return true;
        }
        return false;
    }
};
