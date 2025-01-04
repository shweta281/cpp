class Solution {
public:
    bool hasMatch(string s, string p) {
        string start = "", end = "";
        int n = s.length(), m = p.length();
        bool flag = 0;
        for (int i = 0; i < m; i++){
            if(p[i] == '*'){
                flag = 1;
                continue;
            }
            if(flag){
                end += p[i];
            } else {
                start += p[i];
            }
        }
        int st = s.find(start);
        string temp =s.substr(st+start.length(), n); 
        int e = temp.find(end);
        if(st == -1 || e == -1){
            return false;
        }
        if(end == "" || start == ""){
            return true;
        }
        return true;
        
    }
};©leetcode
